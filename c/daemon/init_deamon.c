#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

void init_deamon()
{
	int pid;
	int i;

	/*如果是父进程，结束*/
	if(pid=fork())
	{
		exit(0);
	}
	else if(pid<0)
	{
		exit(1);
	}
	/* 是第一子进程，后台继续执行 
	 * 第一自己成成为新的会话组长和进程组长*/
	setsid();
	/*与控制终端分离*/
	if(pid=fork())
	{
		exit(0);//结束第一子进程
	}
	else if (pid<0)
	{
		exit(1);
	}

	/**
	 *	是第二子进程，继续
	 *	第二子进程不再是会话组长
	 *	关闭打开的文件描述符
	 */
	for(i=0;i<NOFILE;++i)
	{
		close(i);
	}
	/* 改变目录到/tmp */
	chdir("/tmp");
	/* 重设文件创建掩模 */
	umask(0);
}
