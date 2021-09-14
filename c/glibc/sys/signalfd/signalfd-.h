#include <sys/signalfd.h>

//signalfd - create a file descriptor for accepting signals
int signalfd(int fd, const sigset_t *mask, int flags);

