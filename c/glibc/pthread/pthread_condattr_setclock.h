#include <pthread.h>

#ifdef __rtaox_debug
#include <bits/time.h>
/* Identifier for system-wide realtime clock.  */
CLOCK_REALTIME		
/* Monotonic system-wide clock.  */
CLOCK_MONOTONIC		
/* High-resolution timer from the CPU.  */
CLOCK_PROCESS_CPUTIME_ID	
/* Thread-specific CPU-time clock.  */
CLOCK_THREAD_CPUTIME_ID	
#endif


//get and set the clock selection condition variable attribute (ADVANCED REALTIME)
//时钟属性的设置与获取（clock）
int pthread_condattr_getclock(const pthread_condattr_t * attr, clockid_t * clock_id);
int pthread_condattr_setclock(pthread_condattr_t *attr, clockid_t clock_id);
//时钟属性的概念：
//    时钟属性控制计算pthread_cond_timewait函数的超时参数（tsptr）时采用的是哪个时钟
//    合法值取自下图列出的时钟ID

//pthread_condattr_setclock函数：
//功能：此函数用于设置pthread_cond_timewait函数使用的时钟ID
//
//pthread_condattr_getclock函数：
//功能：此函数获取可被用于pthread_cond_timedwait函数的时钟ID。pthread_cond_timedwait函数使用前需要用pthread_condattr_t对条件变量进行初始化




