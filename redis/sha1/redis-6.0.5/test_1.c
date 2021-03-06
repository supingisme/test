#include "sha1.h"
#include <stdio.h>



#define BUFSIZE 4096

#define UNUSED(x) (void)(x)
int sha1Test(int argc, char **argv)
{
    SHA1_CTX ctx;
    unsigned char hash[20], buf[BUFSIZE];
    int i;

    UNUSED(argc);
    UNUSED(argv);

    for(i=0;i<BUFSIZE;i++)
        buf[i] = i;

    SHA1Init(&ctx);
    for(i=0;i<1000;i++)
        SHA1Update(&ctx, buf, BUFSIZE);
    SHA1Final(hash, &ctx);

    printf("SHA1=");
    for(i=0;i<20;i++)
        printf("%02x", hash[i]);
    printf("\n");
    return 0;
}


int main(int argc, char **argv)
{
    char str[] = {"abcdefghijklmn"};

    sha1Test(argc, argv);


}

