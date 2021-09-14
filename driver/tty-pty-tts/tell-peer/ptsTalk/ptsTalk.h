/**********************************************************************************************************************
** 
** Copyright (c) 2008-2018 ICT/CAS.
** All rights reserved.
**
** File name: ptsTalk.h
** Description:
**
** Current Version: 
** $Revision$ 
** Author: Rong Tao
** Date: 2020.01
**
***********************************************************************************************************************/

#ifndef _TALK_PTS_H
#define _TALK_PTS_H 1

/* Dependencies ------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/un.h>

#include "easy_macros.h"

/* Constants ---------------------------------------------------------------------------------------------------------*/
/**
 *  伪终端状态
 */
typedef enum {
    PTS_ON,     //伪终端上位（执行了守护进程）
    PTS_OFF,    //伪终端下线（守护进程被杀死，终端被关闭）
}pts_stat;

/**
 *  伪终端类型
 */
typedef enum {
    PTS_THIS,   //本终端
    PTS_PEER    //其他终端
}pts_type;
    
/* Types -------------------------------------------------------------------------------------------------------------*/
/**
 *  伪终端结构体
 */
struct pts_id {
#define PTS_MAGIC	0xaab12cdd  //
	int pts_magic;              //PTS_MAGIC
	int pts_dev_no;             //"/dev/pts/0" -> 0
    int pts_fd;                 //open("/dev/pts/0", O_RDWR)
    int sock_fd;                //socket描述符
    pthread_t       master_task;
    pthread_mutex_t mutex;      //同步
    char unix_path[256];
}_packed;

/**
 *  伪终端绑定的进程
 */
struct pts_process {
    
    pthread_mutex_t mutex;

    char cmd[1024];
    int pipefd_out[2];
    
    int pts_fd;
    
    pthread_t pipe_read_task;
    
    pts_type log_flag;
    
    struct pts_id *pts_current;
    struct pts_id *pts_master;
}_packed;

/* Macros ------------------------------------------------------------------------------------------------------------*/
/* Globals -----------------------------------------------------------------------------------------------------------*/
/* Functions ---------------------------------------------------------------------------------------------------------*/

/**
 *  主伪终端
 *  @params[out]: master    主终端信息
 *  @params[in]: callback   当有伪终端启动守护进程后，此回调函数被调用
 */
int pts_master(const char *name, struct pts_id *master, int (*callback)(struct pts_id*, pts_stat));

/**
 *  从伪终端
 *  @params[out]: slave     从终端信息
 */
int pts_slave(const char *name, struct pts_id* slave);

/**
 *  在主伪终端进程中启动可执行文件
 *  @params[out]: master    主伪终端
 *  @params[out]: process   进程相关信息
 *  @params[in]: cmd_str    启动可执行文件需要运行的bash，支持可变参数列表
 *  例：
 *  @example：bash中启动可执行文件为
 *              [bash$]# ./test -i 1 -s arg
 *            那么使用此接口即可
 *              struct pts_process process;
 *              pts_vexe(&precess, "./%s -i %d -s %s", "test", 1, "arg");
 */
int pts_vexe(struct pts_id *const master, struct pts_process *process, char *cmd_str, ...);

/**
 *  绑定启动的可执行文件与伪终端
 *  @params[in]: pts        伪终端
 *  @params[in]: process    可执行文件：pts_vexe的返回值
 */
int pts_bind_process(struct pts_id *pts, struct pts_process *process);

/**
 *  重置可执行文件到主伪终端
 *  @params[in]: process    可执行文件：pts_vexe的返回值
 */
int pts_reset_process(struct pts_process *process);

/**
 *  输出日志到伪终端
 *  @params[in]: pts        伪终端
 */
int pts_print(struct pts_id *pts, char *fmt, ...);


#endif//_TALK_PTS_H

