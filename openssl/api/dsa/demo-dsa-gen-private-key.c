//密钥生成
#include <string.h>
#include <openssl/dsa.h>

#define RED_START   printf("\033[1;31m");
#define RED_END     printf("\033[m");

int main()
{
    DSA *d;
    int ret,i;
    unsigned char seed[20];
    int counter=2;
    unsigned long h;
    d=DSA_new();

    for(i=0;i<20;i++)
        memset(seed+i,i,1);
    
    /* 生成密钥参数 */
    ret=DSA_generate_parameters_ex(d, 512,seed, 20, &counter,&h,NULL);
    //ret=DSA_generate_parameters_ex(d, 512,NULL,0,NULL,NULL,NULL);
    if(ret!=1)
    {
        DSA_free(d);
        return -1;
    }
    /* 生成密钥 */
    ret=DSA_generate_key(d);
    if(ret!=1)
    {
        DSA_free(d);
        return -1;
    }
    DSA_print_fp(stdout,d,0);
    DSA_free(d);
    return 0;
}

//# ./a.out 
//Private-Key: (512 bit)
//priv:
//    5d:e6:7f:05:04:05:d9:6f:8e:ec:9e:93:74:df:fd:
//    35:31:71:65:ef
//pub: 
//    00:d1:9f:1c:52:f2:25:f9:c8:5f:8a:a9:c1:7a:c9:
//    55:b9:04:6a:02:03:20:98:44:02:be:ad:31:68:e4:
//    3d:39:31:69:8d:93:11:41:c1:94:f2:0d:a5:63:1e:
//    51:a0:09:b1:d0:96:3c:95:7c:04:36:1a:4b:dd:5e:
//    10:03:95:77:f4
//P:   
//    00:d4:b9:4d:47:39:a3:ba:da:af:85:7b:55:4f:e2:
//    93:71:be:2b:e1:a1:aa:4d:6e:5a:1a:ff:ee:e8:bd:
//    58:ec:f5:78:3f:19:d3:85:96:a4:df:83:7f:5b:f7:
//    b2:50:45:9b:3e:3b:4f:cc:fd:25:c5:f9:f3:3f:40:
//    3c:dc:6b:3a:cd
//Q:   
//    00:9f:ac:57:4f:3e:65:8d:13:cb:a1:cd:6e:8e:cc:
//    b2:be:c4:4f:fd:ab
//G:   
//    00:a1:a4:ed:a5:a1:f4:90:44:b8:42:f3:4f:a8:a3:
//    b9:ff:18:e9:72:4e:c7:63:b9:72:9c:71:32:2c:7f:
//    f9:7c:06:b4:eb:c6:2d:3c:4d:a4:83:d7:32:89:ff:
//    75:f3:37:5b:80:f2:66:e2:38:99:25:b7:66:b8:c1:
//    a5:4b:e8:b8:44

