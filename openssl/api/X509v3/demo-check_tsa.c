//另外本函数支持其他用途的验证，示例如下：
#include <openssl/x509v3.h>

int cb_check_tsa(X509_PURPOSE *purpose,const X509 *x,int isCA)
{
    int flag;
    printf("------------my check!-----------------\n");
    /* 针对x 添加判断函数 */
    flag=*((int *)(purpose->usr_data));
    if(flag)
        return 1; /* 由此功能 */
    else
        return 0; /* 无此功能 */
}

int main()
{
    X509 *x=0;
    int id,len,ret;
    FILE *fp;
    unsigned char buf[5000],*p;
    int tsaFlag;
    tsaFlag=1;
    ret=X509_PURPOSE_add(1000,1000,0,cb_check_tsa,"tsa","checkTsa",&tsaFlag);
    fp=fopen("alg.cer","rb");
    len=fread(buf,1,5000,fp);
    fclose(fp);
    p=buf;
    d2i_X509(&x,&p,len);
    id=1000;
    ret=X509_check_purpose(x,id,0);
    if(ret==1)
    {
        printf("purpose check ok!\n");
    }
    else
    {
        printf("purpose check failed!\n");
    }
    X509_free(x);
    return 0;
}

//本程序通过调用函数X509_PURPOSE_add 添加一个X509_PURPOSE 内部数据结构，
//然后再验证证书是否有此用途。用户所要实现的为X509_PURPOSE 中的回调函数，在此回
//调函数中，用户根据证书信息来判断证书是否有此用途。如果用户还需要其他的信息才能作
//出判断，可以另外获取X509_PURPOSE 数据结构中的usr_data。usr_data 为一个void 指针
//类型。用户可在调用X509_PURPOSE_add 函数时将它写入对应的X509_PURPOSE 数据结
//构(上例中的tsaFlag)。

