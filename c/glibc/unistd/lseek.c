//lseek - reposition read/write file offset
#include <sys/types.h>
#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence);
