#include <sched.h>

//sched_yield - yield the processor
//放弃CPU： 该接口导致调用的线程放弃CPU，
//这个线程被移动到优先级队列的队尾，另一个线程将被运行
int sched_yield(void);

//也可以看
#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <pthread.h>

//int pthread_yield(void);


SYSCALL_DEFINE0(sched_yield)
{
	do_sched_yield();
	return 0;
}

/**
 * sys_sched_yield - yield the current processor to other threads.
 *
 * This function yields the current CPU to other tasks. If there are no
 * other threads running on this CPU then this function will return.
 *
 * Return: 0.
 */
static void do_sched_yield(void)
{
	struct rq_flags rf;
	struct rq *rq;

	rq = this_rq_lock_irq(&rf);

	schedstat_inc(rq->yld_count);
	current->sched_class->yield_task(rq);

	/*
	 * Since we are going to call schedule() anyway, there's
	 * no need to preempt or enable interrupts:
	 */
	preempt_disable();
	rq_unlock(rq, &rf);
	sched_preempt_enable_no_resched();

	schedule();
}

