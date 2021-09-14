#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <sched.h>
#include <syscall.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#if 0//如果没定义这个函数，可以使用系统调用
int setns(int fd, int nstype)
{
    syscall(SYS_setns, fd, nstype);
}
#endif

int main(int argc, char *argv[])
{
    int fd;
    if(argc < 3) {
        printf("%s /proc/PID/ns/FILE cmd args...\n", argv[0]);
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1){
        printf("error open %s\n", argv[1]);
        exit(1);
    }

    //./a.out /proc/self/ns/ipc ls  必须这样
    //CLONE_NEWIPC:     fd must refer to an IPC namespace.
    if(setns(fd, CLONE_NEWIPC) == -1){
        printf("error setns.\n");
        close(fd);
        exit(1);
    }

    execvp(argv[2], &argv[2]);
    
}

