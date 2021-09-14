#include <unistd.h>
#include <stdio.h>
#include <sys/eventfd.h>

int main()
{
    int efd = eventfd(0, EFD_NONBLOCK|EFD_CLOEXEC|EFD_SEMAPHORE);
    int ret;
    
    eventfd_write(efd, 2);
    eventfd_write(efd, 3);
//    eventfd_write(efd, 4);


    eventfd_t count;

    ret = eventfd_read(efd, &count);
    printf("ret = %d, count = %d\n", ret, count);
    ret = eventfd_read(efd, &count);
    printf("ret = %d, count = %d\n", ret, count);
    ret = eventfd_read(efd, &count);
    printf("ret = %d, count = %d\n", ret, count);
    ret = eventfd_read(efd, &count);
    printf("ret = %d, count = %d\n", ret, count);
    ret = eventfd_read(efd, &count);
    printf("ret = %d, count = %d\n", ret, count);
    ret = eventfd_read(efd, &count);
    printf("ret = %d, count = %d\n", ret, count);
    
//    [root@localhost eventfd]# gcc demo-multi-readwrite-semaphore.c 
//    [root@localhost eventfd]# ./a.out 
//    ret = 0, count = 1
//    ret = 0, count = 1
//    ret = 0, count = 1
//    ret = 0, count = 1
//    ret = 0, count = 1
//    ret = -1, count = 1



    close(efd);
}


