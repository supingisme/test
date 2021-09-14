//编程示例
//下面的例子用来生成一个 crl 文件。


#include <openssl/x509.h>
int main()
{
    int ret,len;
    unsigned char *buf,*p;
    unsigned long e=RSA_3;
    FILE *fp;
    time_t t;
    X509_NAME *issuer;
    ASN1_TIME *lastUpdate,*nextUpdate,*rvTime;
    X509_CRL *crl=NULL;
    X509_REVOKED *revoked;
    EVP_PKEY *pkey;
    ASN1_INTEGER *serial;
    RSA *r;
    BIGNUM *bne;
    BIO *bp;
    /* 生成密钥*/
    bne=BN_new();
    ret=BN_set_word(bne,e);
    r=RSA_new();
    ret=RSA_generate_key_ex(r,1024,bne,NULL);
    if(ret!=1)
    {
    printf("RSA_generate_key_ex err!\n");
    return -1;
    }
    pkey=EVP_PKEY_new();
    EVP_PKEY_assign_RSA(pkey,r);
    crl=X509_CRL_new();
    /* 设置版本*/
    ret=X509_CRL_set_version(crl,3);
    /* 设置颁发者*/
    issuer=X509_NAME_new();
    ret=X509_NAME_add_entry_by_NID(issuer,NID_commonName,V_ASN1_PRINTABLESTRING, "CRL issuer",10,-1,0);
    ret=X509_CRL_set_issuer_name(crl,issuer);
    /* 设置上次发布时间*/
    lastUpdate=ASN1_TIME_new();
    t=time(NULL);
    ASN1_TIME_set(lastUpdate,t);
    ret=X509_CRL_set_lastUpdate(crl,lastUpdate);
    /* 设置下次发布时间*/
    nextUpdate=ASN1_TIME_new();
    t=time(NULL);
    ASN1_TIME_set(nextUpdate,t+1000);
    ret=X509_CRL_set_nextUpdate(crl,nextUpdate);
    /* 添加被撤销证书序列号*/
    revoked=X509_REVOKED_new();
    serial=ASN1_INTEGER_new();
    ret=ASN1_INTEGER_set(serial,1000);
    ret=X509_REVOKED_set_serialNumber(revoked,serial);
    rvTime=ASN1_TIME_new();
    t=time(NULL);
    ASN1_TIME_set(rvTime,t+2000);
    ret=X509_CRL_set_nextUpdate(crl,rvTime);
    ret=X509_REVOKED_set_revocationDate(revoked,rvTime);
    ret=X509_CRL_add0_revoked(crl,revoked);
    /* 排序*/
    ret=X509_CRL_sort(crl);
    /* 签名*/
    ret=X509_CRL_sign(crl,pkey,EVP_md5());
    /* 写入文件*/
    bp=BIO_new(BIO_s_file());
    BIO_set_fp(bp,stdout,BIO_NOCLOSE);
    X509_CRL_print(bp,crl);
    len=i2d_X509_CRL(crl,NULL);
    buf=malloc(len+10);
    p=buf;
    len=i2d_X509_CRL(crl,&p);
    fp=fopen("crl.crl","wb");
    fwrite(buf,1,len,fp);
    fclose(fp);
    BIO_free(bp);
    X509_CRL_free(crl);
    free(buf);
    getchar();
    return 0;
}


//[root@localhost api]# ./a.out 
//Certificate Revocation List (CRL):
//        Version 4 (0x3)
//    Signature Algorithm: md5WithRSAEncryption
//        Issuer: /CN=CRL issuer
//        Last Update: Jan 19 02:03:09 2020 GMT
//        Next Update: Jan 19 02:36:29 2020 GMT
//Revoked Certificates:
//    Serial Number: 03E8
//        Revocation Date: Jan 19 02:36:29 2020 GMT
//    Signature Algorithm: md5WithRSAEncryption
//         49:72:19:45:9f:b3:71:61:ed:25:6c:d4:00:cd:d4:a4:50:37:
//         61:4a:4b:6f:b1:33:12:49:00:59:e4:e2:54:9a:3b:8c:99:05:
//         f2:36:4f:ef:08:8d:1e:c0:05:56:47:da:d5:5c:c5:17:51:b1:
//         ac:ed:8d:af:d7:8c:c0:58:ff:b4:95:71:61:91:36:66:3a:2b:
//         e1:1d:e8:ba:c1:7e:c3:f4:1f:77:3c:c2:90:18:1b:8f:a3:ef:
//         81:02:71:fd:70:a9:85:63:ff:98:39:6e:7c:9c:cd:0a:b3:00:
//         7d:b9:9b:f9:eb:66:e1:d4:f0:72:0b:a6:85:e2:b4:6b:69:b9:
//         4f:c5
//
//[root@localhost api]# 

