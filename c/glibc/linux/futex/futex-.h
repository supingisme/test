#include <linux/futex.h>
#include <sys/time.h>

//fast user-space locking
//The futex() system call provides a method for a program to wait for a value at a given address to change,
int futex(int *uaddr, int op, int val, const struct timespec *timeout,
         int *uaddr2, int val3);

//         futex(clear_child_tid, FUTEX_WAKE, 1, NULL, NULL, 0);

//查看 test/c/glibc/linux/unistd/set_tid_address.h 
//              long set_tid_address(int *tidptr);