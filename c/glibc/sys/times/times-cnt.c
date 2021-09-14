#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

#define BUFFER_SIZE  4 * 1024

int main()
{
    int sc_clk_tck;
    sc_clk_tck = sysconf(_SC_CLK_TCK);

    struct tms begin_tms, end_tms;
    clock_t begin, end;
    system("date");
    begin = times(&begin_tms);
    sleep(2);
    end = times(&end_tms);

    printf("real time: %lf\n", (end - begin) / (double)sc_clk_tck);
    printf("user time: %lf\n",
            (end_tms.tms_utime - begin_tms.tms_utime) / (double)sc_clk_tck);
    printf("sys time: %lf\n",
            (end_tms.tms_stime - begin_tms.tms_stime) / (double)sc_clk_tck);
    printf("child user time: %lf\n",
            (end_tms.tms_cutime - begin_tms.tms_cutime) / (double)sc_clk_tck);
    printf("child sys time: %lf\n",
            (end_tms.tms_cstime - begin_tms.tms_cstime) / (double)sc_clk_tck);
    return 0;
}
