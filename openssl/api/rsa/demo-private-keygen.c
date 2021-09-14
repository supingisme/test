//密钥生成
#include <openssl/rsa.h>
int main()
{
    RSA *r;
    int bits=512,ret;
    unsigned long e=RSA_3;
    BIGNUM *bne;
    r=RSA_generate_key(bits,e,NULL,NULL);
    RSA_print_fp(stdout,r,11);
    RSA_free(r);
    bne=BN_new();
    ret=BN_set_word(bne,e);
    r=RSA_new();
    ret=RSA_generate_key_ex(r,bits,bne,NULL);
    if(ret!=1)
    {
        printf("RSA_generate_key_ex err!\n");
        return -1;
    }
    RSA_free(r);
    return 0;
}
//说明：
//调用 RSA_generate_key 和RSA_generate_key_ex 函数生成RSA 密钥，
//调用 RSA_print_fp 打印密钥信息。
//输出：
//                # ./a.out 
//               Private-Key: (512 bit)
//               modulus:
//                   00:da:8e:6b:a9:fa:81:5c:eb:c4:7d:05:de:72:11:
//                   c6:ea:8d:d2:f1:f3:58:57:63:e2:da:4f:0b:ff:35:
//                   2f:a7:99:62:95:27:b4:06:ec:9b:1b:ec:dd:2a:23:
//                   2d:be:e7:45:9a:bc:7b:be:21:eb:fd:33:b1:0e:7b:
//                   51:76:ff:56:67
//               publicExponent: 3 (0x3)
//               privateExponent:
//                   00:91:b4:47:c6:a7:00:e8:9d:2d:a8:ae:94:4c:0b:
//                   d9:f1:b3:e1:f6:a2:3a:e4:ed:41:e6:df:5d:54:ce:
//                   1f:c5:0f:b1:00:f1:93:82:49:a3:22:dc:4c:71:93:
//                   75:c3:9b:21:9b:12:53:d9:a9:4b:38:ab:16:8c:94:
//                   1f:f4:6f:2c:6b
//               prime1:
//                   00:ec:cc:18:ec:7c:44:46:d0:8c:29:ba:12:e9:2c:
//                   fd:83:e1:fc:32:d3:8d:0e:e8:87:a5:ad:0c:92:8b:
//                   87:ff:f1
//               prime2:
//                   00:ec:47:a4:6a:47:39:df:97:16:40:c5:b3:13:ec:
//                   81:0f:50:24:cb:24:16:ec:3f:ab:69:8e:90:8e:fc:
//                   d0:93:d7
//               exponent1:
//                   00:9d:dd:65:f2:fd:82:d9:e0:5d:71:26:b7:46:1d:
//                   fe:57:eb:fd:77:37:b3:5f:45:af:c3:c8:b3:0c:5d:
//                   05:55:4b
//               exponent2:
//                   00:9d:85:18:46:da:26:95:0f:64:2b:2e:77:62:9d:
//                   ab:5f:8a:c3:32:18:0f:48:2a:72:46:5f:0b:09:fd:
//                   e0:62:8f
//               coefficient:
//                   3e:1f:64:c9:b4:7f:b1:b8:40:31:11:c5:20:05:25:
//                   52:eb:62:e0:4e:c1:b2:c0:f8:6e:29:4e:0a:66:1f:
//                   b2:85
//

