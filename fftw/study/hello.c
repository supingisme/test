#include <stdio.h>
#include <fftw3.h>

#define N 1024
#define FFT_WINSZ_IN 	1024
#define FFT_WINSZ_OUT	(FFT_WINSZ_IN / 2) + 1



void demo_fftw_1_double()
{
    int i;
    
    fftw_plan plan;
    double *fft_in;
    fftw_complex *fft_out;

    fft_in = (double *)fftw_malloc(sizeof(double) * FFT_WINSZ_IN);

    for(i=0;i<FFT_WINSZ_IN;i++)
    {
        fft_in[i] = 10.0;
    }
    
	fft_out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * FFT_WINSZ_IN);
    plan = fftw_plan_dft_r2c_1d(FFT_WINSZ_IN, fft_in, fft_out, FFTW_MEASURE); 

    fftw_execute(plan); 
    // 执行变换
    //... 
    for(i=0;i<FFT_WINSZ_IN;i++)
    {
        printf("%lf \t %lf\n", fft_out[0], fft_out[1]);
    }
    
    fftw_destroy_plan(plan); 
    fftw_free(fft_in); 
    fftw_free(fft_out); 
    
}
void demo_fftw_2_complex()
{
    fftw_complex *in, *out; 
    fftw_plan p; 

    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N); 
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N); 
    
    // 输入数据in 赋值
    
    p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE); 
    fftw_execute(p); 
    // 执行变换
    //... 
    
    fftw_destroy_plan(p); 
    fftw_free(in); 
    fftw_free(out); 
}

int main()
{
    demo_fftw_1_double();
    demo_fftw_2_complex();
    
    
    return 0;
}
