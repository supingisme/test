#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BM 19778                    // The ASCII code for BM
#define sizeofFILE 14
#define sizeofINFO 40

float v[2000][2000];

typedef struct _tagBMP_FILEHEADER
{ 
unsigned short bfType;        //2Bytes，必须为"BM"，即0x424D 才是Windows位图文件
unsigned int   bfSize;         //4Bytes，整个BMP文件的大小
unsigned short bfReserved1;  //2Bytes，保留，为0
unsigned short bfReserved2;  //2Bytes，保留，为0
unsigned int   bfOffBits;     //4Bytes，文件起始位置到图像像素数据的字节偏移量
} BMP_FILEHEADER;

typedef struct _tagBMP_INFOHEADER
{
unsigned int     biSize;    //4Bytes，INFOHEADER结构体大小，存在其他版本I NFOHEADER，用作区分
unsigned int     biWidth;    //4Bytes，图像宽度（以像素为单位）
unsigned int     biHeight;    //4Bytes，图像高度，+：图像存储顺序为Bottom2Top，-：Top2Bottom
unsigned short   biPlanes;    //2Bytes，图像数据平面，BMP存储RGB数据，因此总为1
unsigned short   biBitCount;         //2Bytes，图像像素位数
unsigned int     biCompression;     //4Bytes，0：不压缩，1：RLE8，2：RLE4
unsigned int     biSizeImage;       //4Bytes，4字节对齐的图像数据大小
unsigned int     biXPelsPerMeter;   //4 Bytes，用象素/米表示的水平分辨率
unsigned int     biYPelsPerMeter;   //4 Bytes，用象素/米表示的垂直分辨率
unsigned int     biClrUsed;          //4 Bytes，实际使用的调色板索引数，0：使用所有的调色板索引
unsigned int     biClrImportant;     //4 Bytes，重要的调色板索引数，0：所有的调色板索引都重要
}BMP_INFOHEADER;

void write_file(FILE *fp,BMP_FILEHEADER *fileheader)
{
   fseek(fp, 0L, SEEK_SET);
   fwrite(&fileheader->bfType, 2L, 1, fp);
   fwrite(&fileheader->bfSize, 4L, 1, fp);
   fwrite(&fileheader->bfReserved1, 2L, 1, fp);
   fwrite(&fileheader->bfReserved2, 2L, 1, fp);
   fwrite(&fileheader->bfOffBits, 4L, 1, fp);
   fseek(fp, 0L, SEEK_SET);
}
void write_info(FILE *fp, BMP_INFOHEADER *infoheader)
{
   fseek(fp, sizeofFILE, SEEK_SET);
   fwrite(&infoheader->biSize, 4L, 1, fp);
   fwrite(&infoheader->biWidth, 4L, 1, fp);
   fwrite(&infoheader->biHeight, 4L, 1, fp);
   fwrite(&infoheader->biPlanes, 2L, 1, fp);
   fwrite(&infoheader->biBitCount, 2L, 1, fp);
   fwrite(&infoheader->biCompression, 4L, 1, fp);
   fwrite(&infoheader->biSizeImage, 4L, 1, fp);
   fwrite(&infoheader->biXPelsPerMeter, 4L, 1, fp);
   fwrite(&infoheader->biYPelsPerMeter, 4L, 1, fp);
   fwrite(&infoheader->biClrUsed, 4L, 1, fp);
   fwrite(&infoheader->biClrImportant, 4L, 1, fp);
}
void main(int argc, char* argv[])
{
   int stride,i,j,width,height,nx,nz;
   unsigned char* pixout=NULL;

   BMP_FILEHEADER fileheader;
   BMP_INFOHEADER infoheader;

   width=600;    nx=600;
   height=300;   nz=300;


   FILE *fp,*fpout;
   if((fp=fopen("migration.dat","rb"))==NULL){printf("Open file error! \n");exit(0);}
   for(i=0;i<nx;i++)
      for(j=0;j<nz;j++)
          fread(&v[i][j],sizeof(float),1,fp);

   fpout=fopen("out.bmp","wb");


   fileheader.bfType=19778;
   fileheader.bfSize=54+3*width*height;
   fileheader.bfReserved1=0;
   fileheader.bfReserved2=0;
   fileheader.bfOffBits=54;
   if (BM != fileheader.bfType){printf("This file is not bmp file.!!!\n");exit(1);}
   printf("\nThe BMP picture file header as following:\n");
   printf("--Type=%u,\n",fileheader.bfType);
   printf("--Size=%d,\n",fileheader.bfSize);
   printf("--Reserved1=%u,\n",fileheader.bfReserved1);
   printf("--Reserved2=%u,\n",fileheader.bfReserved2);
   printf("--bfOffBits=%d,\n",fileheader.bfOffBits);
   write_file(fpout,&fileheader);

   infoheader.biSize=40;
   infoheader.biWidth=width;
   infoheader.biHeight=height;
   infoheader.biPlanes=1;
   infoheader.biBitCount=24;
   infoheader.biCompression=0;
   infoheader.biSizeImage=3*width*height;
   infoheader.biXPelsPerMeter=0;
   infoheader.biYPelsPerMeter=0;
   infoheader.biClrUsed=0;
   infoheader.biClrImportant=0;
   printf("\nThe BMP picture information header as following:\n");
   printf("--size=%d,\n",infoheader.biSize);
   printf("--width=%d,\n",infoheader.biWidth);
   printf("--height=%d,\n",infoheader.biHeight);
   printf("--planes=%u,\n",infoheader.biPlanes);
   printf("--bitcount=%u,\n",infoheader.biBitCount);
   printf("--Compression=%d,\n",infoheader.biCompression);
   printf("--SizeImage=%d,\n",infoheader.biSizeImage);
   printf("--XPelsPerMeter=%d,\n",infoheader.biXPelsPerMeter);
   printf("--YPelsPerMeter=%d,\n",infoheader.biYPelsPerMeter);
   printf("--ClrUsed=%d,\n",infoheader.biClrUsed);
   printf("--ClrImportant=%d,\n",infoheader.biClrImportant);
   write_info(fpout,&infoheader);

   stride=(24*width+31)/8;
   stride=stride/4*4;
   pixout=malloc(stride);
 
   fseek(fpout, fileheader.bfOffBits, SEEK_SET);

   for( j=0 ; j<height ; j++ )
   {
      for( i=0 ; i<width ; i++ )
       {
          pixout[i*3+2]=(unsigned char)v[(int)(i*1.0*nx/width)][(int)((height-1-j)*1.0*nz/height)];
          pixout[i*3+1]=(unsigned char)v[(int)(i*1.0*nx/width)][(int)((height-1-j)*1.0*nz/height)];
          pixout[i*3]  =(unsigned char)v[(int)(i*1.0*nx/width)][(int)((height-1-j)*1.0*nz/height)];
       }
      fwrite(pixout, 1, stride, fpout);
   }

   fclose(fp);
}


