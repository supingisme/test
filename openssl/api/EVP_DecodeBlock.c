/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <string.h>
#include <openssl/evp.h>

int main()
{
    unsigned char in[500],out[800],d[500],*p;
    int inl,i,len,pad;
    for(i=0;i<500;i++)
        memset(&in[i],i,1);
    printf("please input how much(<500) to base64 : \n");
    scanf("%d",&inl);
    len=EVP_EncodeBlock(out,in,inl);
    printf("%s\n",out);
    p=out+len-1;
    pad=0;
    for(i=0;i<4;i++)
    {
        if(*p=='=')
        pad++;
        p--;
    }
    len=EVP_DecodeBlock(d,out,len);
    len-=pad;
    if((len!=inl) || (memcmp(in,d,len)))
        printf("err!\n");
    printf("test ok.\n");
    return 0;
}
//对于非格式化数据的BASE64 解码可以调用
//EVP_DecodeBlock 函数，不过用户需要自己去除后面填充的0。

