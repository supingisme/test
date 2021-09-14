/**
 *	线程取消		P148
 *
 *	We alluded to a problem with Figure 8.4 if the calling thread gets blocked in the call to
 *	pthread-cond-wait and the thread is then canceled. A thread may be canceled by
 *	any other thread in the same process when the other thread calls pthread-cancel, a
 *	fundion whose only argument is the thread ID to cancel.
 */
#include <pthread.h>

//pthread_cancel - send a cancellation request to a thread
//向线程发送取消请求
int pthread_cancel(pthread_t tid);

/**
 *	线程取消		P148
 *
 *	We alluded to a problem with Figure 8.4 if the calling thread gets blocked in the call to
 *	pthread-cond-wait and the thread is then canceled. A thread may be canceled by
 *	any other thread in the same process when the other thread calls pthread-cancel, a
 *	fundion whose only argument is the thread ID to cancel.
 */
#include <pthread.h>

//int pthread_cancel(pthread_t tid);

/**
 *	Under normal circumstances, a thread terminates when it exits normally, either by
 *	returning from its thread function or by calling pthread_exit. However, it is possible
 *	for a thread to request that another thread terminate.This is called canceling a thread.
 *	To cancel a thread, call pthread_cancel, passing the thread ID of the thread to be
 *	canceled. A canceled thread may later be joined; in fact, you should join a canceled
 *	thread to free up its resources, unless the thread is detached (see Section 4.1.5,“Thread
 *	Attributes”).The return value of a canceled thread is the special value given by
 *	PTHREAD_CANCELED.
 */
#include <pthread.h>
#include <stdio.h>
#include <string.h>
/* An array of balances in accounts, indexed by account number. */
float* account_balances;
/* Transfer DOLLARS from account FROM_ACCT to account TO_ACCT. Return
 * 0 if the transaction succeeded, or 1 if the balance FROM_ACCT is
 * too small. */
int process_transaction (int from_acct, int to_acct, float dollars)
{
	int old_cancel_state;
	/* Check the balance in FROM_ACCT. */
	if (account_balances[from_acct] < dollars)
		return 1;
	/* Begin critical section. */
	pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, &old_cancel_state);
	/* Move the money. */
	account_balances[to_acct] += dollars;
	account_balances[from_acct] -= dollars;
	/* End critical section. */
	pthread_setcancelstate (old_cancel_state, NULL);
	return 0;
}







