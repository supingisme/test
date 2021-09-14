/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <string.h>
#include <openssl/evp.h>
int main()
{
    EVP_ENCODE_CTX ectx,dctx;
    unsigned char in[500],out[800],d[500];
    int inl,outl,i,total,ret,total2;
    EVP_EncodeInit(&ectx);
    for(i=0;i<500;i++)
    memset(&in[i],i,1);
    inl=500;
    total=0;
    EVP_EncodeUpdate(&ectx,out,&outl,in,inl);
    total+=outl;
    EVP_EncodeFinal(&ectx,out+total,&outl);
    total+=outl;
    printf("%s\n",out);
    EVP_DecodeInit(&dctx);
    outl=500;
    total2=0;
    ret=EVP_DecodeUpdate(&dctx,d,&outl,out,total);
    if(ret<0)
    {
        printf("EVP_DecodeUpdate err!\n");
        return -1;
    }
    total2+=outl;
    ret=EVP_DecodeFinal(&dctx,d,&outl);
    total2+=outl;
    return 0;
}
//本例中先编码再解码。
//编码调用次序为 EVP_EncodeInit、EVP_EncodeUpdate(可以多次)和EVP_EncodeFinal。
//解码调用次序为 EVP_DecodeInit、EVP_DecodeUpdate(可以多次)和EVP_DecodeFinal。
//注意：采用上述函数 BASE64 编码的结果不在一行，解码所处理的数据也不在一行。
//用上述函数进行BASE64 编码时，输出都是格式化输出。特别需要注意的是，BASE64 解码
//时如果某一行字符格式超过80 个，会出错。如果要BASE64 编码的结果不是格式化的，可
//以直接调用函数：EVP_EncodeBlock。同样对于非格式化数据的BASE64 解码可以调用
//EVP_DecodeBlock 函数，不过用户需要自己去除后面填充的0。

