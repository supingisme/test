#include <stdio.h>
#include <stdlib.h>
#include <fftw3.h>
#include <string.h>
#include <complex.h>

int N=3;

//[root@localhost study]# gcc fftw3_example2.c -lm -lfftw3 -std=c99
//[root@localhost study]# ./a.out

int main()
{

    fftw_complex *in, *out;

    fftw_plan p;

    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

    for(int i=0;i<N;i++)
    {
        in[i][0]=i+1;
        in[i][1]=0;
    }
    memset(out,0,sizeof(out));
//    FFTW_ESTIMATE   估计
//    FFTW_MEASURE    测量


    p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE/*测量*/);
    fftw_execute(p);
    for(int i=0;i<N;i++)
    {
        printf("%f %f i \n",out[i][0],out[i][1]);
    }
    p = fftw_plan_dft_1d(N, out, in, FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(p);
//...
    for(int i=0;i<N;i++)
    {
        printf("%f %f i \n",in[i][0],in[i][1]);
    }

    fftw_destroy_plan(p);

    fftw_free(in);
    fftw_free(out);
    return 0;

}

