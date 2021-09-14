//之二：采用PKCS12_parse 函数，下面的例子用于解析pkcs12 文件，获取证书，以及RSA
//密钥信息。
int p12_parse
(
    char *p12,int p12Len,char *pass,char *cert,int *certlen,
    char *n,int *nlen,
    char *e,int *elen,
    char *d,int *dlen,
    char *p,int *plen,
    char *q,int *qlen,
    char *dmp1,int *dmp1len,
    char *dmq1,int *dmq1len,
    char *iqmp,int *iqmplen
)
{
    int ret=0,certl;
    char *pp=NULL,*certp=NULL,*derCert=NULL;
    BIO *bp=NULL;
    PKCS12 *PK12=NULL;
    EVP_PKEY *pkey=NULL;
    X509 *cc=NULL;
    OpenSSL_add_all_algorithms();
    pp=p12;
    d2i_PKCS12(&PK12,&pp,p12Len);
    if(PK12==NULL)
    {
        printf("d2i_PKCS12 err\n");
        return -1;
    }
    ret=PKCS12_parse(PK12,pass,&pkey,&cc,NULL);
    if(ret!=1)
    {
        printf("PKCS12_parse err\n");
        return -1;
    }
    /* cert */
    certl=i2d_X509(cc,NULL);
    certp=(char *)malloc(certl+10);
    derCert=certp;
    certl=i2d_X509(cc,&certp);
    memcpy(cert,derCert,certl);
    *certlen=certl;
    free(derCert);
    /* n */
    *nlen=BN_bn2bin(pkey->pkey.rsa->n,n);
    /* e */
    *elen=BN_bn2bin(pkey->pkey.rsa->e,e);
    /* d */
    *dlen=BN_bn2bin(pkey->pkey.rsa->d,d);
    /* p */
    *plen=BN_bn2bin(pkey->pkey.rsa->p,p);
    /* q */
    *qlen=BN_bn2bin(pkey->pkey.rsa->q,q);
    /* dmp1 */
    *dmp1len=BN_bn2bin(pkey->pkey.rsa->dmp1,dmp1);
    /* dmq1 */
    *dmq1len=BN_bn2bin(pkey->pkey.rsa->dmq1,dmq1);
    /* iqmp */
    *iqmplen=BN_bn2bin(pkey->pkey.rsa->iqmp,iqmp);
    
    PKCS12_free(PK12);
    
    OPENSSL_free(PK12);
    
    return 0;
}



