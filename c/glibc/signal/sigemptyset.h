
#include <signal.h>


//sigemptyset, sigfillset, sigaddset, sigdelset, sigismember - POSIX signal set operations.

int sigemptyset(sigset_t *set);

int sigfillset(sigset_t *set);

int sigaddset(sigset_t *set, int signum);

int sigdelset(sigset_t *set, int signum);

int sigismember(const sigset_t *set, int signum);

