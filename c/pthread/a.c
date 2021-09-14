/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:41 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:39 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:23 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:59 CST. */





#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <malloc.h>
#include <assert.h>


int main()
{
    pthread_mutex_t cell_mgmt_log_mutex;
    pthread_mutexattr_t cell_mgmt_log_mutexattr;

    int32_t res = -1;


    /*!< initilize timer_mutex */
    res = pthread_mutexattr_init(&cell_mgmt_log_mutexattr);/*default attribute*/
    assert(!res);
    res = pthread_mutexattr_settype(&cell_mgmt_log_mutexattr, PTHREAD_MUTEX_RECURSIVE);/*can  recursive*/
    assert(!res);
    res = pthread_mutex_init(&cell_mgmt_log_mutex,&cell_mgmt_log_mutexattr);
    assert(!res);


    pthread_mutex_lock(&cell_mgmt_log_mutex);

    pthread_mutex_unlock(&cell_mgmt_log_mutex);


}