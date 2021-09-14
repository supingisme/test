
#include <signal.h>

//examine and change blocked signals
//检测并改变被阻塞的信号
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

