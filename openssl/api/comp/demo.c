#include <string.h>
#include <openssl/comp.h>
int main()
{
    COMP_CTX *ctx;
    int len,olen=100,ilen=50,i,total=0;
    unsigned char in[50],out[100];
    unsigned char expend[200];
#ifdef _WIN32
    ctx=COMP_CTX_new(COMP_rle());
#else
    /* for linux */
    ctx=COMP_CTX_new(COMP_zlib());
#endif
    for(i=0;i<20;i++)
        memset(&in[i],i,1);
    
    total=COMP_compress_block(ctx,out,olen,in,50);
    len=COMP_expand_block(ctx,expend,200,out,total);

    printf("total: %d, len: %d\n", total, len);

    for(i=0;i<50;i++)
        printf("%2d ", in[i]);
    printf("\n");
    
    for(i=0;i<50;i++)
        printf("%2d ", out[i]);
    printf("\n");
    
    for(i=0;i<50;i++)
        printf("%2d ", expend[i]);
    printf("\n");

    
    COMP_CTX_free(ctx);
    return 0;
}

//1) COMP_rle
//			返回 openssl 实现的空压缩算法，返回值为一个COMP_METHOD。
//2) COMP_zlib
//			返回基于zlib 库的COMP_METHOD。
//3） COMP_CTX_new
//			初始化上下文，输入参数为 COMP_METHOD。
//4） COMP_compress_block
//			压缩计算。
//5） COMP_expand_block
//			解压计算。


