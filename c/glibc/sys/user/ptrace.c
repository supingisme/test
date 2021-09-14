/*64位下乌班图程序*/

#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <sys/user.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>

//读取子进程系统调用参数

int main()
{
	pid_t child;
	long orig_rax;
	int status;
	int iscalling=0;
	struct user_regs_struct regs;

	child = fork();
	if(child==0){
		ptrace(PTRACE_TRACEME,0,NULL,NULL);
		execl("/bin/ls","ls","-l","-h",NULL);
	}else{
		while(1)
		{
			wait(&status);
			if(WIFEXITED(status))
				break;
			orig_rax=ptrace(PTRACE_PEEKUSER,child,8*ORIG_RAX,NULL);
			if(orig_rax == SYS_write){
				ptrace(PTRACE_GETREGS,child,NULL,&regs);
				if(!iscalling){
					iscalling =1;
					printf("SYS_write call with %lld, %lld, %lld\n",regs.rdi,regs.rsi,regs.rdx);
				} else{
					printf("SYS_write call return %lld\n",regs.rax);
					iscalling = 0;
				}                                  


			}
			ptrace(PTRACE_SYSCALL,child,NULL,NULL);
		}
	}
	return 0;
}

/**
 *	可以看到ls -l -h 执行了六次SYS_write系统调用。
 *	读取寄存器中的参数时，可以使用PTRACE_PEEKUSER一个字一个字读取，
 *	也可以使用PTRACE_GETREGS参数直接将寄存器的值读取到结构体user_regs_struct 中，该结构体定义在sys/user.h中
 *
 *	对于PTRACE_STSCALL参数，该参数会像PTRACE_CONT一样使暂停的子进程继续执行，
 *	并在子进程下次进行系统调用前或系统调后，向子进程发送SINTRAP信号量，让子进程暂停。
 *
 *	WIFEXITED函数(宏)函数用来检查子进程是暂停还准备退出。
 */

