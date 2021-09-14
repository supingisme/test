#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

//隔离网络接口 - CLONE_NEWNET
//要使用不同的网络接口创建子进程，请使用CLONE_NEWNET：
//
//pid_t pid = clone(child_fn, child_stack+1024*1024, CLONE_NEWNET , NULL);
//要创建虚拟网络适配器，我们可以运行ip命令：
//
//# sudo ip link add name veth0 type veth peer name veth1 netns [child pid]
//# sudo ifconfig veth0 10.0.0.3
//现在，子进程应该运行命令：
//
//# ifconfig veth1 10.0.0.4
//我们可以对所有这些命令进行编码，但为简单起见，请使用system（3）库函数



static char child_stack[1024*1024];

static int child_fn() {
  sleep(1);
  system("ifconfig veth1 10.0.0.4"); 
  puts("========= child network interfaces ========");
  system("ifconfig -a");
  puts("===========================================");
  sleep(1);
  system("ping -c 3 10.0.0.3");
  return 0;
}

int main() {
  char buf[255]; 

  pid_t pid = clone(child_fn, child_stack+1024*1024, CLONE_NEWNET , NULL);

  sprintf(buf,"ip link add name veth0 type veth peer name veth1 netns %d",pid); 
  system(buf);
  system("ifconfig veth0 10.0.0.3"); 
  
//  veth0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
//          inet 10.0.0.3  netmask 255.0.0.0  broadcast 10.255.255.255
//          inet6 fe80::c81c:b6ff:fe01:b9b7  prefixlen 64  scopeid 0x20<link>
//          ether ca:1c:b6:01:b9:b7  txqueuelen 1000  (Ethernet)
//          RX packets 9  bytes 754 (754.0 B)
//          RX errors 0  dropped 0  overruns 0  frame 0
//          TX packets 20  bytes 2005 (1.9 KiB)
//          TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

  waitpid(pid, NULL, 0);
  return 0;
}
