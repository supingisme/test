//ASN1_STRING *ASN1_STRING_set_by_NID(ASN1_STRING **out, const unsigned char *in, int inlen, int inform, int nid);
//
//根据nid 和输入值获取对应的ASN1_STIRNG 类型。out 为输出，in 为输入数据，
//inlen 为其长度，inform 为输入数据的类型，可以的值有：MBSTRING_BMP、
//MBSTRING_UNIV、MBSTRING_UTF8、MBSTRING_ASC，nid 为数字证书中常用的
//nid，在a_strnid.c 中由全局变量tbl_standard 定义，可以的值有：NID_commonName、
//NID_countryName 、NID_localityName 、NID_stateOrProvinceName 、
//NID_organizationName 、NID_organizationalUnitName 、NID_pkcs9_emailAddress 、
//NID_pkcs9_unstructuredName 、NID_pkcs9_challengePassword 、
//NID_pkcs9_unstructuredAddress 、NID_givenName 、NID_surname 、NID_initials 、
//NID_serialNumber 、NID_friendlyName 、NID_name 、NID_dnQualifier 、
//NID_domainComponent 和NID_ms_csp_name。生成的ASN1_STRING 类型可以为：
//ASN1_T61STRING 、ASN1_IA5STRING 、ASN1_PRINTABLESTRING 、
//ASN1_BMPSTRING、ASN1_UNIVERSALSTRING 和ASN1_UTF8STRING。
//示例 1：

#include <stdio.h>
#include <string.h>
#include <openssl/asn1.h>
#include <openssl/obj_mac.h>
int main()
{
    int inlen,nid,inform,len;
    char in[100],out[100];
    unsigned char *p;
    ASN1_STRING *a;
    int ret;
    FILE *fp;
    
    /* 汉字“赵”的UTF8值,可以用UltraEdit获取*/
    memset(&in[0],0xEF,1);
    memset(&in[1],0xBB,1);
    memset(&in[2],0xBF,1);
    memset(&in[3],0xE8,1);
    memset(&in[4],0xB5,1);
    memset(&in[5],0xB5,1);
    inlen=6;
    inform=MBSTRING_UTF8;
    nid=NID_commonName;
    /* 如果调用下面两个函数，生成的ASN1_STRING类型将是ASN1_UTF8而不是
    ASN1_BMPSTRING */
    ASN1_STRING_set_default_mask(B_ASN1_UTF8STRING);
    ret=ASN1_STRING_set_default_mask_asc("utf8only");
    if(ret!=1)
    {
        printf("ASN1_STRING_set_default_mask_asc err.\n");
        return 0;
    }
    a=ASN1_STRING_set_by_NID(NULL,in,inlen,inform,nid);
    p=out;
    len=i2d_ASN1_BMPSTRING(a,&p);
    fp=fopen("a.cer","w");
    fwrite(out,1,len,fp);
    fclose(fp);
    ASN1_STRING_free(a);
    return 0;
}
//本例根据UTF8 编码的汉字获取nid 为NID_commonName 的ASN1_STRING 类型，其
//结果是一个ASN1_BMPSTRING 类型。

