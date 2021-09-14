#include <stdio.h>
#include <stdlib.h>

#define BITMAPFILEHEADERLENGTH 14   // The bmp FileHeader length is 14
#define BM 19778                    // The ASCII code for BM

unsigned int OffSet = 0;    // OffSet from Header part to Data Part
int width ;          // The Width of the Data Part
int height ;         // The Height of the Data Part
unsigned char ir[2000][2000],or[2000][2000];
unsigned char ig[2000][2000],og[2000][2000];
unsigned char ib[2000][2000],ob[2000][2000];

void bmpoutput(FILE* fpout)
{
         int i, j=0;
         int stride;
          unsigned char* pixout=NULL;
   
          stride=(24*width+31)/8;
          stride=stride/4*4;
          pixout=malloc(stride);
 
          fseek(fpout, OffSet, SEEK_SET);


          for(j=0;j<height;j++)
           {
                for(i=0;i<width;i++)
                  {
                 pixout[i*3+2]=or[j][i];
                 pixout[i*3+1]=og[j][i];
                 pixout[i*3]  =ob[j][i];
                  }
               fwrite(pixout, 1, stride, fpout);
           }
}

void bmpDataPart(FILE* fpin)
{
          int i, j;
          int stride;
          unsigned char* pix=NULL;

          fseek(fpin, OffSet, SEEK_SET);
          stride=(24*width+31)/8;
          stride=stride/4*4;
          pix=malloc(stride);
 
          for(j=0;j<height;j++)
          {
               fread(pix, 1, stride, fpin);

               for(i=0;i<width;i++)
                {
                 ir[j][i]   =pix[i*3+2];
                 ig[j][i]   =pix[i*3+1];
                 ib[j][i]   =pix[i*3];


                 or[j][i]   =pix[i*3+2];
                 og[j][i]   =pix[i*3+1];
                 ob[j][i]   =pix[i*3];
                }
          }
}

void bmpFileTest(FILE* fpin)
{     
     unsigned short bfType = 0;
 
     fseek(fpin, 0L, SEEK_SET);
     fread(&bfType, sizeof(short), 1, fpin);
     if (BM != bfType)
     {
           printf("This file is not bmp file.!!!\n");
           exit(1);
     }
}
/* To get the OffSet of header to data part */
void bmpHeaderPartLength(FILE* fpin)
{
     fseek(fpin, 10L, SEEK_SET);
     fread(&OffSet, sizeof(int), 1, fpin);  
     printf("The Header Part is of length %d.\n", OffSet);
}
/* To get the width and height of the bmp file */
void BmpWidthHeight(FILE* fpin)
{
     fseek(fpin, 18L, SEEK_SET);
     fread(&width, sizeof(int), 1, fpin);
     fseek(fpin, 22L, SEEK_SET);
     fread(&height, sizeof(int), 1, fpin);
     printf("Width == %d.\n", width);
     printf("Height== %d.\n", height);
}

/*********************Main**********************/
int main(int argc, char* argv[])
{
     /* Open bmp file */
     unsigned char *fp_temp;

     FILE *fpin;
     FILE *fpout;
                   printf("\nchar=%d, short=%d, int=%d, float=%d, long=%d\n\n"
                         ,sizeof(char),sizeof(short),sizeof(int),sizeof(float),sizeof(long));

     if((fpin= fopen("b.bmp", "rb"))==NULL){printf("Open bmp failed!!!\n");exit(0);}
     fpout= fopen("out.bmp", "wb");

     bmpFileTest(fpin);                //Test the file is bmp file or not
     bmpHeaderPartLength(fpin);        //Get the length of Header Part
     BmpWidthHeight(fpin);             //Get the width and width of the Data Part
     
     fseek(fpin, 0L, SEEK_SET);
     fseek(fpout, 0L, SEEK_SET);
 
     fp_temp=malloc(OffSet);
     fread(fp_temp, 1, OffSet, fpin);
     fwrite(fp_temp, 1, OffSet, fpout);
     
     bmpDataPart(fpin);                //Reserve the data to file 

/*
 
    here ,you can maintain the bmp picture.
 
*/    
     bmpoutput(fpout);
     fclose(fpin);
     fclose(fpout);
     return 0;
}


