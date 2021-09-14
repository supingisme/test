//OBJ_obj2txt
//ASN1_OBJECT *OBJ_nid2obj(int n);
//根据对象获取对象说明或者 nid，示例：
#include <openssl/asn1.h>
#include <openssl/objects.h>

int main()
{
    char buf[100];
    int buf_len=100;
    ASN1_OBJECT *a;
    a=OBJ_nid2obj(65);
    OBJ_obj2txt(buf,buf_len,a,0);
    printf("%s\n",buf);
    OBJ_obj2txt(buf,buf_len,a,1);
    printf("%s\n",buf);
    return 0;
}
//输出结果：
//sha1WithRSAEncryption
//1.2.840.113549.1.1.5
