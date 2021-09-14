/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:15 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 21日 星期四 09:04:25 CST. */


#include <mqueue.h>

int mq_send(mqd_t mqdes, const char *msg_ptr,
                    size_t msg_len, unsigned msg_prio);

#include <time.h>
#include <mqueue.h>

int mq_timedsend(mqd_t mqdes, const char *msg_ptr,
                    size_t msg_len, unsigned msg_prio,
                    const struct timespec *abs_timeout);

SYSCALL_DEFINE5(mq_timedsend, mqd_t, mqdes, const char __user *, u_msg_ptr,
        size_t, msg_len, unsigned int, msg_prio,
        const struct __kernel_timespec __user *, u_abs_timeout)
{
    struct timespec64 ts, *p = NULL;
    if (u_abs_timeout) {
        int res = prepare_timeout(u_abs_timeout, &ts);
        if (res)
            return res;
        p = &ts;
    }
    return do_mq_timedsend(mqdes, u_msg_ptr, msg_len, msg_prio, p);
}

