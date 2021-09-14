#include <stdio.h>
#include <malloc.h>

#include <X11/Xatom.h>
#include <X11/keysym.h>

int main(int argc, char *argv[])
{    
    FILE *infp=fopen("data.bin", "r");

    int n1, n2, nz;

    n1=64, n2=32;

    float *z;
    
    nz = n1*n2;
	z = malloc(sizeof(float)*nz);
    fread(z,sizeof(float),nz,infp);


    fclose(infp);
    return 0;
}
