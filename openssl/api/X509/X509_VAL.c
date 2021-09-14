#include <string.h>
#include <openssl/x509.h>
int main()
{
    FILE *fp;
    char *buf,*p;
    char read[1024];
    int len;
    X509_VAL *val=NULL,*val2=NULL;
    time_t t;
    /* new 函数 */
    val=X509_VAL_new();
    /* 构造内容 */
    t=time(0);
    ASN1_TIME_set(val->notBefore,t);
    ASN1_TIME_set(val->notAfter,t+1000);
    /* i2d 函数 */
    len=i2d_X509_VAL(val,NULL);
    p=buf=malloc(len);
    len=i2d_X509_VAL(val,&p);
    /* 写入文件 */
    fp=fopen("val.cer","wb");
    fwrite(buf,1,len,fp);
    fclose(fp);
    /* 读文件 */
    fp=fopen("val.cer","rb");
    len=fread(read,1,1024,fp);
    fclose(fp);
    p=read;
    /* d2i 函数 */
    d2i_X509_VAL(&val2,&p,len);
    if(val2==NULL)
    {
        printf("err\n");
    }
    /* free 函数 */
    X509_VAL_free(val);
    if(val2)
    X509_VAL_free(val2);
    free(buf);
    return 0;
}

