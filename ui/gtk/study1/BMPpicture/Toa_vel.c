#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "/home/Toa/hc/cjbsegy.h"
#include "/home/Toa/hc/fft.c"
#include "/home/Toa/hc/alloc.c"
#include "/home/Toa/hc/complex.c"
int main()
{    



	int i,j,k,nx,nz,r;
	float **vp,*layer;
/*******************************************/
/*****change the name and the parameter*****/
        char FN1[250]={"v100200.dat"};
        nx=100;
        nz=200; 
        r=10;
	 vp=alloc2float(nz,nx);
        zero2float(vp,nz,nx);
/********************************************/


      for(i=0;i<nx;i++)
        {
	 for(j=0;j<nz;j++)
	  {

             vp[i][j]=100;
             if(i<nx/2&&j<nz/2)vp[i][j]=200;

             
	  }
	}    

                                    
     
/*********the velocity model ENDing**********/
/********************************************/
	FILE *fp1;
	fp1=fopen(FN1,"wb");
	for(i=0;i<nx;i++)
	   for(j=0;j<nz;j++)
	      fwrite(&vp[i][j],4,1,fp1);
	fclose(fp1); 

    free2float(vp);
        return 0;
}












