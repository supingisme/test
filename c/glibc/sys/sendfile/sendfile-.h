#include <sys/sendfile.h>

//sendfile - transfer data between file descriptors
ssize_t sendfile(int out_fd, int in_fd, off_t *offset, size_t count);

