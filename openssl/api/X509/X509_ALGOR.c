#include <string.h>
#include <openssl/x509.h>
int main()
{
    FILE *fp;
    char *buf,*p;
    char data[]={"12345678"},read[1024];
    int len;
    X509_ALGOR *alg=NULL,*alg2=NULL,*alg3=NULL;
    /* new 函数 */
    alg=X509_ALGOR_new();
    /* 构造内容 */
    alg->algorithm=OBJ_nid2obj(NID_sha256);
    alg->parameter=ASN1_TYPE_new();
    ASN1_TYPE_set_octetstring(alg->parameter,data,strlen(data));
    /* i2d 函数 */
    len=i2d_X509_ALGOR(alg,NULL);
    p=buf=malloc(len);
    len=i2d_X509_ALGOR(alg,&p);
    /* 写入文件 */
    fp=fopen("alg.cer","wb");
    fwrite(buf,1,len,fp);
    fclose(fp);
    /* 读文件 */
    fp=fopen("alg.cer","rb");
    len=fread(read,1,1024,fp);
    fclose(fp);
    p=read;
    /* d2i 函数 */
    d2i_X509_ALGOR(&alg2,&p,len);
    if(alg2==NULL)
    {
        printf("err\n");
    }
    /* dup 函数 */
    alg3=X509_ALGOR_dup(alg);
    /* free 函数 */
    X509_ALGOR_free(alg);
    if(alg2)
    X509_ALGOR_free(alg2);
    X509_ALGOR_free(alg3);
    free(buf);
    return 0;
}

