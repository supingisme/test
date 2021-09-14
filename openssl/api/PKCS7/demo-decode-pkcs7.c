//解码pkcs7
#include <openssl/pkcs7.h>
#include <openssl/objects.h>
int main()
{
    PKCS7 *p7=NULL;
    int ret,len;
    char buf[1000],*p,name[1000];
    FILE *fp;
    fp=fopen("p7_singAndEnv.cer","rb");
    len=fread(buf,1,1000,fp);
    fclose(fp);
    p=buf;
    d2i_PKCS7(&p7,(const unsigned char **)&p,len);
    ret=OBJ_obj2txt(name,1000,p7->type,0);
    printf("type : %s \n",name);
    PKCS7_free(p7);
    return 0;
}
//本例解码 DER 格式的PKCS7 消息。

