#include <stdio.h>
#include <time.h>
#include <stdint.h>

static uint64_t tsc_resolution_hz = 0;
uint64_t          tick_per_usec;

unsigned long timer_get_ticks(void)
{
    unsigned long ret;
    union
    {
        unsigned long tsc_64;
        struct
        {
            unsigned int lo_32;
            unsigned int hi_32;
        };
    } tsc;

    __asm volatile("rdtsc" :
             "=a" (tsc.lo_32),
             "=d" (tsc.hi_32));

     ret = ((unsigned long)tsc.tsc_64);
     return ret;
}


int timer_set_tsc_freq_from_clock(void)
{
#define NS_PER_SEC 1E9
    struct timespec sleeptime = {.tv_nsec = 5E8 }; /* 1/2 second */

    struct timespec t_start, t_end;

    if (clock_gettime(CLOCK_MONOTONIC_RAW, &t_start) == 0)
    {
        unsigned long ns, end, start = timer_get_ticks();
        nanosleep(&sleeptime,NULL);
        clock_gettime(CLOCK_MONOTONIC_RAW, &t_end);
        end = timer_get_ticks();
        ns = ((t_end.tv_sec - t_start.tv_sec) * NS_PER_SEC);
        ns += (t_end.tv_nsec - t_start.tv_nsec);

        double secs = (double)ns/NS_PER_SEC;
        tsc_resolution_hz = (unsigned long)((end - start)/secs);

        tick_per_usec = (tsc_resolution_hz / 1000000);
        printf("System clock (rdtsc) resolution %lld [Hz]\n", tsc_resolution_hz);
        printf("Ticks per us %lld\n", tick_per_usec);
        return 0;
    }

    return -1;
}

int main()
{
	timer_set_tsc_freq_from_clock();

}
