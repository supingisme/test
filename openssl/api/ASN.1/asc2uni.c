//unsigned char *asc2uni(const char *asc, int asclen, unsigned char **uni, int *unilen)
//将ASCII 码转换为unicode，示例：
#include <stdio.h>
#include <openssl/crypto.h>
int main()
{
    unsigned char asc[50]={"B2E2CAD4"};
    unsigned char uni[50],*p,*q;
    int ascLen,unlen;
    ascLen=strlen(asc);
    q=asc2uni(asc,ascLen,NULL,&unlen);//对‘asc2uni’未定义的引用?????????
    OPENSSL_free(q);
    return 0;
}

