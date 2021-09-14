/**********************************************************************************************************************
** 
** Copyright (c) 2008-2018 ICT/CAS.
** All rights reserved.
**
** File name: ptsTalk.c
** Description: 
**
** Current Version: 
** $Revision$ 
** Author: Rong Tao
** Date: 2020.01
**
***********************************************************************************************************************/
    
/* Dependencies ------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <pthread.h>
#include <sys/select.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/ioctl.h>

#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "easy_macros.h"

#include "ptsTalk.h"

/* Constants ---------------------------------------------------------------------------------------------------------*/


/* Types -------------------------------------------------------------------------------------------------------------*/
typedef int (*pts_cb_fn)(struct pts_id*, pts_stat stat);

struct __pts_master_task_arg {
    struct pts_id   *master;
    pts_cb_fn  callback;
};



/* Macros ------------------------------------------------------------------------------------------------------------*/
#define PTS_MAX_SLAVE   10

#define STR_LEN         256

#define PTS_PREFIX      "/dev/pts"

#define PTS_UNSOCKET_PERFIX "/tmp/_pts_unsock_"

//#define CAS(ptr, oldval, newold) __sync_val_compare_and_swap(ptr, oldval, newold)

#define TCATTR_ADD_ECHO(fd) \
    {\
        struct termios old, new;\
        if (tcgetattr (fd, &old) != 0) {\
            perror("tcgetattr.\n");\
        }\
        new = old;\
        new.c_lflag |= ECHO;\
        if (tcsetattr(fd, TCSAFLUSH, &new) != 0) {\
            perror("tcsetattr.\n");\
        }\
    }

#define PTS_ID(ppts) {\
        struct pts_id *__ppts = ppts;\
        __ppts->pts_magic  = PTS_MAGIC;\
        __ppts->pts_dev_no = 9999;\
        char __str[256] = {0};\
        FILE *__fp = popen("tty", "r");\
        fgets(__str, sizeof(__str), __fp);\
        sscanf(__str, "/dev/pts/%d", &__ppts->pts_dev_no);\
        pclose(__fp);\
    }

#define PTS_SEND(fd, buf, size) {\
        size_t __i;\
        for(__i = 0; __i < size; ++__i) {\
            if (ioctl(fd, TIOCSTI, buf + __i) == -1) {\
                perror("ioctl.");\
            }\
        }\
    }




/* Globals -----------------------------------------------------------------------------------------------------------*/

/* Functions ---------------------------------------------------------------------------------------------------------*/

static void _unused __pts_master_sig_handler(int signum)
{
    static long int call_once = 0;
    if(call_once++ == 0)
    {
        printf("Catch the SIGINT signal.\n");
    }
    exit(1);
}

static void _unused __pts_slave_sig_handler(int signum)
{
    printf("Catch the SIGINT signal.\n");
    
    exit(1);
}

static int _unused __pts_tell_unsocket_server(const char *unix_path)
{
    int sockfd, ret = -1;
    struct sockaddr_un srv_addr;
    unlink(unix_path);
    
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("sreate listening socket error.");
        return -1;
    }
    
    srv_addr.sun_family = AF_UNIX;
    strncpy(srv_addr.sun_path, unix_path, sizeof(srv_addr.sun_path)-1);
    
    ret = bind(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
    if(ret == -1)
    {
        perror("cannot bind server socket.");
        close(sockfd);
        unlink(unix_path);
        return -1;
    }
    
    ret = listen(sockfd, PTS_MAX_SLAVE);
    if(ret == -1)
    {
        perror("cannot listen the client connect request.");
        close(sockfd);
        unlink(unix_path);
        return -1;
    }
    return sockfd;
}


static int _unused __pts_tell_unsocket_client(const char *unix_path)
{
    int connect_fd, ret = -1;
    struct sockaddr_un srv_addr;
    
    connect_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(connect_fd < 0)
    {
        perror("create socket error.");
        return -1;
    }
    
    srv_addr.sun_family = AF_UNIX;
    strcpy(srv_addr.sun_path, unix_path);
    
    ret = connect(connect_fd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
    if(ret == -1)
    {
        perror("connect error");
        close(connect_fd);
        return -1;
    }
    return connect_fd;
}


static void *_unused __pts_master_task(void*arg)
{
    struct __pts_master_task_arg *task_arg = (struct __pts_master_task_arg*)arg;
    
    pts_cb_fn slave_callback = (pts_cb_fn)task_arg->callback;
    struct pts_id *master = task_arg->master;
    
    struct _slaves {
        int fd;
        struct pts_id pts;
    }slaves[PTS_MAX_SLAVE];
    
    int connfd; 
    int _unused ret = 0;
    int i;
    int len, msglen;
    struct sockaddr_un _unused clt_addr, srv_addr;

    struct pts_id _unused pts;
    char msg[STR_LEN];

    int maxfd, maxi, nready; 
    fd_set readset, allset;
    int sockfd;

    signal(SIGINT, __pts_master_sig_handler);

    pthread_mutex_lock(&master->mutex);
    master->sock_fd = __pts_tell_unsocket_server(master->unix_path);
    
    setsockopt(master->sock_fd,SOL_SOCKET,SO_REUSEADDR,NULL,0);
	setsockopt(master->sock_fd,SOL_SOCKET,SO_REUSEPORT,NULL,0);
    
    pthread_mutex_unlock(&master->mutex);
    
    for(i=0; i<PTS_MAX_SLAVE; ++i)
	{
		slaves[i].fd = -1;
	}
    
    maxfd = master->sock_fd;
    maxi = -1;
    
    
    FD_ZERO(&allset);
	FD_SET(master->sock_fd, &allset);
    
    chmod(master->unix_path, 0777);
    
    while(1)
    {
        readset = allset;
		nready = select(maxfd+1, &readset, NULL, NULL, NULL);
        if(nready <= 0)
        {
            perror("select error");
            close(master->sock_fd);
            unlink(master->unix_path);
            break;
        }
        if(FD_ISSET(master->sock_fd, &readset))
		{
            len = sizeof(clt_addr);
            connfd = accept(master->sock_fd, (struct sockaddr*)&clt_addr, (socklen_t *)&len);
            if(connfd == 0)
                continue;
            if(connfd < 0)
            {
                perror("cannot accept client connect request.");
                printf("accept fd %d, master->sock_fd %d\n", connfd, master->sock_fd);
                close(master->sock_fd);
                unlink(master->unix_path);
                break;
            }
            printf("accept fd %d, master->sock_fd %d\n", connfd, master->sock_fd);
            
			for(i=0; i<PTS_MAX_SLAVE; ++i)
			{
				if(slaves[i].fd < 0)
				{
					slaves[i].fd = connfd;
					break;
				}
                if(PTS_MAX_SLAVE == i)
                {
                    perror("too many connection.\n");
                    exit(1);
                }
			}
            FD_SET(connfd, &allset);
            if(connfd > maxfd)
			{
				maxfd = connfd;
			}
            if(i > maxi)
			{
				maxi = i;
			}
        }
        
        for(i=0; i<=maxi; ++i)
		{
            if((sockfd = slaves[i].fd ) < 0)
			{
				continue;
			}
            if(FD_ISSET(sockfd, &readset))
			{   
                memset(msg, 0, STR_LEN);
                msglen = read(sockfd, msg, sizeof(msg));
                if(msglen <= 0)
                {
                    close(sockfd);
                    FD_CLR(sockfd, &allset);
                    printf("CLOSE: fd %d\n", sockfd);
                    slave_callback((struct pts_id*)&slaves[i].pts, PTS_OFF);

                    close(slaves[i].pts.pts_fd);
                    printf("CLOSE: fd slaves[i].pts.pts_fd = %d, sockfd %d\n", slaves[i].pts.pts_fd, sockfd);
                    
                    memset(&slaves[i].pts, 0, sizeof(struct pts_id));
                    
                    slaves[i].fd = -1;
                }
                
				int *magic = (int *)msg;
				if(*magic == PTS_MAGIC)
				{
				    struct pts_id _pts;
				    memcpy(&slaves[i].pts, msg, sizeof(struct pts_id));
                    memcpy(&_pts, msg, sizeof(struct pts_id));

                    char pts_name[256] = {0};
                    sprintf(pts_name, "%s/%d", PTS_PREFIX, _pts.pts_dev_no);
                    _pts.pts_fd = open(pts_name, O_RDWR);

                    slaves[i].pts.pts_fd = _pts.pts_fd;
                    
                    TCATTR_ADD_ECHO(_pts.pts_fd);
                    
                    slave_callback((struct pts_id*)&_pts, PTS_ON);
                    
                    struct pts_id tellpts;
                    PTS_ID(&tellpts);
                    write(sockfd, &tellpts, sizeof(tellpts)); 
				}
            }
        }
    }
    
    close(master->sock_fd);
    
    printf("CLOSE: fd %d\n", master->sock_fd);
    
    free(arg);
    
    return NULL;
}


static void _unused pts_slave_deamon()
{
	int pid;
	int _unused i;

	/*如果是父进程，结束*/
	if((pid=fork())) {
		exit(0);
	} else if(pid<0) {
		exit(1);
	}
	/* 是第一子进程，后台继续执行 
	 * 第一自己成成为新的会话组长和进程组长 */
	setsid();
    
	/*与控制终端分离*/
	if((pid=fork())) {
		exit(0);//结束第一子进程
	} else if (pid<0) {
		exit(1);
	}

	/*  是第二子进程，继续
	 *	第二子进程不再是会话组长
	 *	关闭打开的文件描述符 */
//	for(i=0;i<NOFILE;++i)
//	{
//		close(i);
//	}
	/* 改变目录到/tmp */
//	chdir("/tmp");
	/* 重设文件创建掩模 */
//	umask(0);
}



/**
 *  主伪终端
 *  @params[out]: master    主终端信息
 *  @params[in]: callback   当有伪终端启动守护进程后，此回调函数被调用
 */
int pts_master(const char *name, struct pts_id *master, int (*callback)(struct pts_id*, pts_stat))
{
    PTS_ID(master);
    
    pthread_mutex_init(&master->mutex, NULL);
    
    struct __pts_master_task_arg *arg = (struct __pts_master_task_arg*)malloc(sizeof(struct __pts_master_task_arg));
    
    arg->master = master;
    arg->callback = callback;
    strcpy(master->unix_path, PTS_UNSOCKET_PERFIX);
    strcat(master->unix_path, name);
    
    return pthread_create(&master->master_task, NULL, &__pts_master_task, arg);
}

/**
 *  从伪终端
 *  @params[out]: slave     从终端信息
 */
int pts_slave(const char *name, struct pts_id *slave)
{
//    pts_slave_deamon();

    int _unused ret = 0;
    struct sockaddr_un _unused srv_addr;
    int _unused i;
    
    signal(SIGINT, __pts_slave_sig_handler);
    
    pthread_mutex_init(&slave->mutex, NULL);

    pthread_mutex_lock(&slave->mutex);
    strcpy(slave->unix_path, PTS_UNSOCKET_PERFIX);
    strcat(slave->unix_path, name);
    
    slave->sock_fd = __pts_tell_unsocket_client(slave->unix_path);
    pthread_mutex_unlock(&slave->mutex);
    
    struct pts_id tellpts;
    PTS_ID(&tellpts);
    
    ret = write(slave->sock_fd, &tellpts, sizeof(tellpts));   
    
    read(slave->sock_fd, slave, sizeof(struct pts_id)); 

    char pts_name[256] = {0};
    sprintf(pts_name, "%s/%d", PTS_PREFIX, slave->pts_dev_no);
    slave->pts_fd = open(pts_name, O_RDWR);

    close(tellpts.pts_fd);
    
    printf("CLOSE: fd %d\n", tellpts.pts_fd);
    
    return 0;
}

/**
 *  输出日志到伪终端
 *  @params[in]: pts        伪终端
 */
int pts_print(struct pts_id *pts, char *fmt, ...)
{
	char pts_name[256] = {0};
	char line[1024] = {0};
    int n = 0;
    
	sprintf(pts_name, "%s/%d", PTS_PREFIX, pts->pts_dev_no);
    
	va_list va;
	va_start(va, fmt);
	n = vsprintf(line, fmt, va);
	va_end(va);
    
    /**
     *  作为terminal的输出
     */
    write(pts->pts_fd, line, strlen(line));
    
	return n;
}


static void *__pipe_read_fn(void*arg)
{
    struct pts_process *process = (struct pts_process *)arg;
    char buf[STR_LEN*2] = {0};
    int ret;
    
    FILE*istream = fdopen (process->pipefd_out[0], "r");

    int len;
    
    while(1)
    {
        len = read(fileno(istream), buf, STR_LEN*2);
        
        switch(process->log_flag)
        {
            case PTS_PEER:
                ret = write(process->pts_fd, buf, len);
                if(ret <=0)
                {
                    perror("write error.");
                    close(process->pts_fd);
                    printf("CLOSE: fd %d\n", process->pts_fd);
                    pts_reset_process(process);
                    write(process->pts_fd, buf, len);
                }
                break;

            case PTS_THIS:
                ret = write(fileno(stdout), buf, len);
                if(ret <=0)
                {
                    perror("write error.");
                }
//                fflush(stdout);
                break;
        }       
    }
    return NULL;
}

/**
 *  在主伪终端进程中启动可执行文件
 *  @params[out]: process   进程相关信息
 *  @params[in]: cmd_str    启动可执行文件需要运行的bash，支持可变参数列表
 *  例：
 *  @example：bash中启动可执行文件为
 *              [bash$]# ./test -i 1 -s arg
 *            那么使用此接口即可
 *              struct pts_process process;
 *              pts_vexe(&precess, "./%s -i %d -s %s", "test", 1, "arg");
 */
int pts_vexe(struct pts_id *const master, struct pts_process *process, char *cmd_str, ...)
{
    if(!master || !process || !cmd_str)
    {
        fprintf(stderr, "nullpointer error.\n");
        return -1;
    }
    char dup_std_cmd[1100] = {0};

    /* 组建可变列表 */
    va_list va;
    va_start(va, cmd_str);
    vsprintf(process->cmd, cmd_str, va);
    va_end(va);

    /* 创建管道 */
    if (pipe(process->pipefd_out))
    {
        fprintf (stderr, "Create Pipe failed.\n");
        return -1;
    }
    
    /* 默认与父进程公用一个 PTS */
    process->pts_fd = master->pts_fd;
    
#define DUP_STD_CMD_FMT    "%s 1>&%d 2>&%d &"
#define DUP_STD_CMD_       process->cmd,process->pipefd_out[1], process->pipefd_out[1]

    /* 启动命令组建 */
    sprintf(dup_std_cmd, DUP_STD_CMD_FMT, DUP_STD_CMD_);
    
    process->log_flag = PTS_THIS;

    process->pts_master = master;
    
    pthread_mutex_init(&process->mutex, NULL);

    /* 创建stdout线程 */
    pthread_create(&process->pipe_read_task, NULL, __pipe_read_fn, process);

    /* 启动 */
    return system(dup_std_cmd);
}

/**
 *  绑定启动的可执行文件与伪终端
 *  @params[in]: pts        伪终端
 *  @params[in]: process    可执行文件：pts_vexe的返回值
 */
int pts_bind_process(struct pts_id *pts, struct pts_process *process)
{
    pthread_mutex_lock(&process->mutex);
    
    process->log_flag=PTS_PEER;

    if(process->pts_fd)
    {
        close(process->pts_fd);
        printf("CLOSE: fd %d (%s)\n", process->pts_fd, __func__);
    }
    process->pts_fd = pts->pts_fd;
    
    process->pts_current = pts;
    
    pthread_mutex_unlock(&process->mutex);

    return 0;
}

/**
 *  重置可执行文件到主伪终端
 *  @params[in]: process    可执行文件：pts_vexe的返回值
 */
int pts_reset_process(struct pts_process *process)
{
    pthread_mutex_lock(&process->mutex);
    
    process->log_flag=PTS_THIS;
    
    process->pts_fd = process->pts_master->pts_fd;
    process->pts_current = process->pts_master;
    
    pthread_mutex_unlock(&process->mutex);
    
    return 0;
}

