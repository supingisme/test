#include <stdio.h>
#include <endian.h>

union timestamp {
    struct{
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned int year:12;   //[2019]
    unsigned int month:4;   //[1-12]
    unsigned int day:4;     //[1-31]
    unsigned int hour:4;    //[0-23]
    unsigned int min:4;     //[0-59]
    unsigned int sec:4;     //[0-59]
#elif __BYTE_ORDER == __BIG_ENDIAN
    unsigned int sec:4;     //[0-59]
    unsigned int min:4;     //[0-59]
    unsigned int hour:4;    //[0-23]
    unsigned int day:4;     //[1-31]
    unsigned int month:4;   //[1-12]
    unsigned int year:12;   //[2019]
#endif
    }date;
    unsigned int data;
};

#include <sys/time.h>

int main()
{
    union timestamp ts1;
    ts1.data = 1507601525;

    printf("\tyear\tmonth\tday\thour\tmin\tsec\n");
    printf("\t%d\t%d\t%d\t%d\t%d\t%d\n", ts1.date.year, ts1.date.month, ts1.date.day,
                                         ts1.date.hour, ts1.date.min,  ts1.date.sec);
    printf("\t%02x\t%02x\t%02x\t%02x\t%02x\t%02x\n", ts1.date.year, ts1.date.month, ts1.date.day,
                                                     ts1.date.hour, ts1.date.min,  ts1.date.sec);

    struct timeval tv1;
    gettimeofday(&tv1, NULL);

    printf("sec=%ld, usec=%ld\n", tv1.tv_sec, tv1.tv_usec);

    return 0;
}
