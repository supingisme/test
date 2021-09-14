
#include <sys/ptrace.h>

//long ptrace(enum __ptrace_request request, pid_t pid,
//            void *addr, void *data);

//ptrace追踪子进程执行exec()
//
#include <stdio.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/reg.h>   /* For constants ORIG_RAX etc */

int main()
{
	pid_t child;
	long orig_rax;
	child=fork();
	if(child==0){
		ptrace(PTRACE_TRACEME,0,NULL,NULL);
		execl("/bin/ls","ls",NULL);
	}else{
		wait(NULL);
		orig_rax = ptrace(PTRACE_PEEKUSER, child, 8*ORIG_RAX, NULL);
		printf("The child made a system call %ld\n",orig_rax);
		ptrace(PTRACE_CONT,child,NULL,NULL);
	}

}
/**
 *	execl()函数对应的系统调用为__NR_execve，系统调用值为59。父进程通过调用fork()来创建子进程。
 *	在子进程中，先运行patrce().请求参数设为PTRACE_TRACE,来告诉内核当前进程被父进程trace，
 *	每当有信号量传递到当前进程，该进程会暂停，提醒父进程在wait()调用处继续执行。
 *	然后再调用execl()。当execl()函数成功执行后，新程序运行之前，SIGTRAP信号量会被发送到该进程，
 *	让子进程停止，这时父进程会在wait相关调用处被通知，获取子进程的控制权，可以查看子进程内存和寄存器相关信息。
 */
