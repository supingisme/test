//pthread_attr_setschedparam,  pthread_attr_getschedparam  -  set/get  scheduling  parameter  attributes in
//thread attributes object
//
//SYNOPSIS
#include <pthread.h>

struct sched_param {
   int sched_priority;     /* Scheduling priority */
};

//SCHED_OTHER   the standard round-robin time-sharing policy;
//
//SCHED_BATCH   for "batch" style execution of processes; and
//
//SCHED_IDLE    for running very low priority background jobs.
//
////The following "real-time" policies are also supported, for special time-critical applications  that  need
////precise control over the way in which runnable processes are selected for execution:
//
//SCHED_FIFO    a first-in, first-out policy; and
//
//SCHED_RR      a round-robin policy.

//int pthread_attr_setschedparam(pthread_attr_t *attr,
//                                const struct sched_param *param);
int pthread_attr_getschedparam(pthread_attr_t *attr,
                                    struct sched_param *param);

//Compile and link with -pthread.
//RETURN VALUE
//On success, these functions return 0; on error, they return a nonzero error number.
//<2>.调度参数：
//               
//函数pthread_attr_getschedparam 和pthread_attr_setschedparam分别
//用来设置和得到线程的调度参数。

   

int pthread_attr_getschedparam(const pthread_attr_t *,struct sched_param *);
int pthread_attr_setschedparam(pthread_attr_t *,const struct sched_param *);
//参数：
//        attr            线程变量属性
//        param        sched_parm 结构体
//若成功返回0，若失败返回-1。

///usr/include /bits/sched.h
struct sched_param
{
       int sched_priority;    //!> 参数的本质就是优先级
};
//注意：大的权值对应高的优先级!
//系统支持的最大和最小的优先级值可以用函数：
//sched_get_priority_max和sched_get_priority_min得到！

#include <pthread.h>
int sched_get_priority_max( int policy );
int sched_get_priority_min( int policy );
//参数：max_：    系统支持的优先级的最小值
//        min_ ：    系统支持的优先级的最大值
//
//使用：max_ = sched_get_priority_max( policy );
//        min_ = sched_get_priority_min( policy );
//        注意参数是policy调用策略，也就是说对于不同的策略的值是不
//        一样的！
//
//附录：来自
//http://www.yuanma.org/data/2006/0823/article_1392.htm
//policy = SCHED_OTHER
//max_priority = 0
//min_priority = 0
//
//Show SCHED_FIFO of priority
//max_priority = 99
//min_priority = 1
//
//Show SCHED_RR of priority
//max_priority = 99
//min_priority = 1
//
//Show priority of current thread
//priority = 0
//

