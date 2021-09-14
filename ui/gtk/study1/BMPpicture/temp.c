typedef struct tagBITMAPFILEHEADER
{ 
unsigned short bfType;        //2Bytes，必须为"BM"，即0x424D 才是Windows位图文件
unsigned int   bfSize;         //4Bytes，整个BMP文件的大小
unsigned short bfReserved1;  //2Bytes，保留，为0
unsigned short bfReserved2;  //2Bytes，保留，为0
unsigned int   bfOffBits;     //4Bytes，文件起始位置到图像像素数据的字节偏移量
} BITMAPFILEHEADER;

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
unsigned int    biClrUsed;          //4 Bytes，实际使用的调色板索引数，0：使用所有的调色板索引
unsigned int   biClrImportant;     //4 Bytes，重要的调色板索引数，0：所有的调色板索引都重要
}BMP_INFOHEADER;

typedef struct _tagRGBQUAD
{
BYTE  rgbBlue;       //指定蓝色强度
BYTE  rgbGreen;      //指定绿色强度
BYTE  rgbRed;        //指定红色强度
 BYTE  rgbReserved;  //保留，设置为0
} RGBQUAD;


// 数据类型转化 float  转化为 unsigned char
int convertF1ToU1(float * src, unsigned char * des, int width, int height)
{
    int i, j, temp;
    for(i = 0; i < height; i ++)
    {
        for(j = 0; j < width; j ++)
        {
             temp = (int)(src[i * width + j]);
             des[i * width + j] = (unsigned char)temp;
        }
    }
    return 0;
}
// 数据类型转化 unsigned char 转化为 float
int convertU1ToF1(unsigned char * src, float * des, int width, int height)
{
    int i, j;
    for(i = 0; i < height; i ++)
    {
        for(j = 0; j < width; j ++)
        {
             des[i * width + j] = (float)src[i * width + j];    
        }
    }
    return 0;
}
