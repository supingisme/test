#include <sys/signalfd.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 *  这个例子只是很简单的说明了使用signalfd的方法，并没有真正发挥它的作用，
 *  有了这个API，就可以将信号处理作为IO看待，
 *  每一个信号集合（或者某一个对应的信号）就会有对应的文件描述符，这样将信号
 *  处理的流程大大简化，将应用程序中的业务作为文件来操作，也体现了linux下的
 *  一切皆文件的说法，非常好，假如有很多种信号等待着处理，每一个信号描述符对
 *  待一种信号的处理，那么就可以将信号文件描述符设置为非阻塞，同时结合epoll使
 *  用，对信号的处理转化为IO复用，和这个有相似之处的API还有timerfd
 */


#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)
 
int
main(int argc, char *argv[])
{
    sigset_t mask;
    int sfd;
    struct signalfd_siginfo fdsi;
    ssize_t s;
 
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGQUIT);
 
    /* 阻塞信号以使得它们不被默认的处理试方式处理 */
 
    if (sigprocmask(SIG_BLOCK, &mask, NULL) == -1)
        handle_error("sigprocmask");
 
    sfd = signalfd(-1, &mask, 0);
    if (sfd == -1)
        handle_error("signalfd");
 
    for (;;) {
        s = read(sfd, &fdsi, sizeof(struct signalfd_siginfo));
        if (s != sizeof(struct signalfd_siginfo))
            handle_error("read");
 
        if (fdsi.ssi_signo == SIGINT) {
            printf("Got SIGINT\n");
        } else if (fdsi.ssi_signo == SIGQUIT) {
            printf("Got SIGQUIT\n");
            exit(EXIT_SUCCESS);
        } else {
            printf("Read unexpected signal\n");
        }
    }
}

