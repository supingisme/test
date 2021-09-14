
#include <linux/unistd.h>

//set pointer to thread ID
long set_tid_address(int *tidptr);
//------------------------------------------------------------
//对每个进程来说，内核维护修改两个属性： set_child_tid 和 clear_child_tid 
//。这俩默认为NULL
//
//set_child_tid   如果进程用clone CLONE_CHILD_SETTID 创建，set_child_tid 值将被设置为 ctid 
//            系统调用的参数 passed ， 当 set_child_tid 被设置后， 
//            该进程发生的第一件事时，将PID写入这个地址。
//
//clear_child_tid 如果进程用clone CLONE_CHILD_CLEARTID 创建，clear_child_tid 将被设置
//
//当一个进程设置了 clear_child_tid ，如果这个进程与另一个进程或者线程共享内存， 当 
//0 被写入特定的地址 clear_child_tid 并且内核执行下面的操作 
//
//    futex(clear_child_tid, FUTEX_WAKE, 1, NULL, NULL, 0); fast user-space locking 
//
//这个操作的作用是如唤醒一个futex wait的进程，
//------------------------------------------------------------


SYSCALL_DEFINE1(set_tid_address, int __user *, tidptr)
{
	current->clear_child_tid = tidptr;

	return task_pid_vnr(current);
}

