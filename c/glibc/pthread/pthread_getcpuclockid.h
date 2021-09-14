#include <pthread.h>
#include <time.h>

//retrieve ID of a thread's CPU time clock
//获取线程运行时间,老铁
int pthread_getcpuclockid(pthread_t thread, clockid_t *clock_id);

//Compile and link with -pthread.
//RETURN VALUE
//       On success, this function returns 0; on error, it returns a nonzero error number.

#ifdef __rtoax_debug
A(){
    static void print_clock(char *msg, clockid_t cid)
    {
        struct timespec ts;

        printf("%s", msg);
        if (clock_gettime(cid, &ts) == -1)
            fprintf(stderr, "clock_gettime");
        printf("%4ld.%03ld\n", ts.tv_sec, ts.tv_nsec / 1000000);
    }

    ret = pthread_getcpuclockid(thread_id, &clockid);
    print_clock("  Child", clockid);
}
#endif


#include <time.h>

//obtain ID of a process CPU-time clock
int clock_getcpuclockid(pid_t pid, clockid_t *clock_id);

//Link with -lrt (only for glibc versions before 2.17).
//
//Feature Test Macro Requirements for glibc (see feature_test_macros(7)):
//
//    clock_getcpuclockid():
//       _XOPEN_SOURCE >= 600 || _POSIX_C_SOURCE >= 200112L

