#include"NativeMethod.h"
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
#include <string.h>
#include <cuda_runtime.h>


void check_gpu_error (const char *msg) 
/*< check GPU errors >*/
{
    cudaError_t err = cudaGetLastError ();
    if (cudaSuccess != err) { 
	printf("Cuda error: %s: %s\n", msg, cudaGetErrorString (err)); 
	exit(0);   
    }
}
__global__ void fun(float *val,int nx,int nz)
{		
	 int id=threadIdx.x+blockDim.x*blockIdx.x;
    
        if(id<nx*nz)
                val[id] = id+1;

}

JNIEXPORT void JNICALL Java_NativeMethod_writefloat
  (JNIEnv *env, jobject obj, jint nx, jint nz){

	float *v,*vv;

      char FN1[250]={"v.dat"};
	FILE *fp;
      fp=fopen(FN1,"wb");

        printf("Rong Tao shinidaye\n");

    	 v=(float*)malloc(nx*nz*sizeof(float));

        cudaSetDevice(0);// initialize device, default device=0;
	 check_gpu_error("Failed to initialize device!");

        cudaMalloc(&vv, nx*nz*sizeof(float));
        cudaMemset(vv, 0, nx*nz*sizeof(float));

        fun<<<(nx*nz+511)/512,512>>>(vv, nx, nz);

       cudaMemcpy(v, vv, nx*nz*sizeof(float), cudaMemcpyDeviceToHost);

        fwrite(v,sizeof(float),nx*nz, fp);

        fclose(fp);
}
