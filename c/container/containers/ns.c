#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>


int clone(int (*fn)(void *), void *child_stack,
          int flags, void *arg, .../* pid_t *ptid, struct user_desc *tls, pid_t *ctid */ );
//要在Linux中创建新进程，我们可以使用fork（2）或clone（2）系统调用。
//我们使用fork（2）创建一个带有单独内存映射的新子进程（使用CoW），
//我们使用clone（2）创建一个与其父级共享资源的子进程。
//克隆的一种用途是实现多线程，另一种用途是实现名称空间。
//
//具有clone（2）的命名空间
//要在新的名称空间和隔离的资源中创建子进程，我们需要使用以下一个或多个标志：
//
//CLONE_NEWNET –隔离网络设备
//CLONE_NEWUTS –主机名和域名（UNIX时间共享系统）
//CLONE_NEWIPC – IPC对象
//CLONE_NEWPID – PID
//CLONE_NEWNS –挂载点（文件系统）
//CLONE_NEWUSER –用户和组



static char child_stack[5000];


void grchild(int num)
{
  printf("child(%d) in ns my PID: %d Parent ID=%d\n", num, getpid(),getppid());
  sleep(5);
  puts("end child");
}

int child_fn(int ppid) {
  int i;
  printf("PID: %ld Parent:%ld\n", (long)getpid(), getppid());
  printf("ppid  = %d\n", ppid);
  for(i=0;i<3;i++)
  {
   	if(fork() == 0)
  	{
  		grchild(i+1);  
  		exit(0);
  	}
  	kill(ppid,SIGKILL); // no effect 
  }
  sleep(2);
  kill(2,SIGKILL); // kill the first child
  sleep(10);
  return 0;
}

int main() {
  pid_t pid = clone(child_fn, child_stack+5000, CLONE_NEWPID , getpid());
  printf("clone() = %d\n", pid);

  waitpid(pid, NULL, 0);
  return 0;
}
