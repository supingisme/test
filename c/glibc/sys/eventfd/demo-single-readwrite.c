#include <unistd.h>
#include <stdio.h>
#include <sys/eventfd.h>

int main()
{
    int efd = eventfd(0, EFD_NONBLOCK|EFD_CLOEXEC);

    eventfd_write(efd, 2);

    eventfd_t count;

    eventfd_read(efd, &count);

    printf("count = %d\n", count);

    close(efd);
}
