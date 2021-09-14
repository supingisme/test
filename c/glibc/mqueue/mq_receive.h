/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:15 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 21日 星期四 09:04:25 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 21日 星期四 08:27:35 CST. */



#include <mqueue.h>

ssize_t mq_receive(mqd_t mqdes, char *msg_ptr,
                        size_t msg_len, unsigned *msg_prio);

#include <time.h>
#include <mqueue.h>

//从1970.01.01计算超时
//timeout.tv_sec = time(NULL)+2;
//n= mq_timedreceive(mqd, buffer, 1024, 0, &timeout);
ssize_t mq_timedreceive(mqd_t mqdes, char *msg_ptr,
                        size_t msg_len, unsigned *msg_prio,
                        const struct timespec *abs_timeout);

                        
SYSCALL_DEFINE5(mq_timedreceive, mqd_t, mqdes, char __user *, u_msg_ptr,
        size_t, msg_len, unsigned int __user *, u_msg_prio,
        const struct __kernel_timespec __user *, u_abs_timeout)
{
    struct timespec64 ts, *p = NULL;
    if (u_abs_timeout) {
        int res = prepare_timeout(u_abs_timeout, &ts);
        if (res)
            return res;
        p = &ts;
    }
    return do_mq_timedreceive(mqdes, u_msg_ptr, msg_len, u_msg_prio, p);
}

