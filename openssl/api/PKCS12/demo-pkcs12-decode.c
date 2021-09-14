#include <string.h>
#include <openssl/pkcs12.h>
int X509_ALGOR_print(BIO *bp,X509_ALGOR *signature)
{
    int nid;
    unsigned char *p;
    PBEPARAM *pbe=NULL;
    nid=OBJ_obj2nid(signature->algorithm);
    switch(nid)
    {
        case NID_md5WithRSAEncryption:
            printf("md5WithRSAEncryption");
            break;
        case NID_sha1WithRSAEncryption:
            printf("sha1WithRSAEncryption");
            break;
        case NID_rsaEncryption:
            printf("rsaEncryption");
            break;
        case NID_sha1:
            printf("sha1");
            break;
        case NID_pbe_WithSHA1And3_Key_TripleDES_CBC:
            printf("NID_pbe_WithSHA1And3_Key_TripleDES_CBC");
            break;
        default:
            printf("unknown signature.");
            break;
    }
    if(signature->parameter!=NULL)
    {
        if(nid==NID_pbe_WithSHA1And3_Key_TripleDES_CBC)
        {
            printf("算法参数:\n");
            p=signature->parameter->value.sequence->data;
            d2i_PBEPARAM(&pbe,&p,signature->parameter->value.sequence->length);
            printf("salt : \n");
            i2a_ASN1_INTEGER(bp,pbe->salt);
            printf("\n");
            printf("iter : %d\n",ASN1_INTEGER_get(pbe->iter));
        }
    }
    printf("\n");
    return 0;
}
void X509_SIG_print(BIO *bp,X509_SIG *a)
{
    if(a->algor!=NULL)
    {
        printf("算法:\n");
        X509_ALGOR_print(bp,a->algor);
    }
    if(a->digest!=NULL)
    {
        printf("摘要:\n");
        i2a_ASN1_STRING(bp,a->digest,1);
    }
}
void PKCS12_SAFEBAG_print(BIO *bp,PKCS12_SAFEBAG *bag)
{
    int nid,attrnum,certl,len=50,k,n,x;
    unsigned char *p,buf[50];
    PBEPARAM *pbe=NULL;
    X509_ATTRIBUTE *attr;
    ASN1_TYPE *type;
    X509 *cert=NULL;
    nid=OBJ_obj2nid(bag->type);
    if((nid==NID_pkcs8ShroudedKeyBag)||
    (nid==NID_pbe_WithSHA1And3_Key_TripleDES_CBC)) /* pkcs 8 */
    {
        nid=OBJ_obj2nid(bag->value.shkeybag->algor->algorithm);
        if(nid==NID_pbe_WithSHA1And3_Key_TripleDES_CBC)
        {
            /* alg */
            X509_SIG_print(bp,bag->value.shkeybag);
        }
    }
    else if(nid==NID_certBag)
    {
        nid=OBJ_obj2nid(bag->value.bag->type);
        if(nid==NID_x509Certificate)
        {
            p=bag->value.bag->value.x509cert->data;
            certl=bag->value.bag->value.x509cert->length;
            d2i_X509(&cert,&p,certl);
            if(cert!=NULL)
            {
                X509_print(bp,cert);
            }
        }
    }
    printf("attris : \n");
    attrnum=sk_X509_ATTRIBUTE_num(bag->attrib);
    for(k=0;k<attrnum;k++)
    {
        attr=sk_X509_ATTRIBUTE_value(bag->attrib,k);
        nid=OBJ_obj2nid(attr->object);
        OBJ_obj2txt(buf,len,attr->object,1);
        printf("object : %s,nid is %d\n",buf,nid);
        if(attr->single==0) /* set */
        {
            n=sk_ASN1_TYPE_num(attr->value.set);
            for(x=0;x<n;x++)
            {
                type=sk_ASN1_TYPE_value(attr->value.set,x);
                if((type->type!=V_ASN1_SEQUENCE) &&
                (type->type!=V_ASN1_SET))
                {
                    if(type->type==V_ASN1_OCTET_STRING)
                        i2a_ASN1_INTEGER(bp,type->value.octet_string);
                    else
                        ASN1_STRING_print(bp,(ASN1_STRING*)type->value.ptr);
                }
            }
        }
        printf("\n");
    }
}
int main()
{
    FILE *fp;
    PKCS12 *p12=NULL;
    PKCS7 *p7=NULL,*one;
    unsigned char buf[10000],*p;
    int len,i,num,j,count,ret;
    STACK_OF(PKCS7) *p7s;
    STACK_OF(PKCS12_SAFEBAG) *bags;
    PKCS12_SAFEBAG *bag;
    PBEPARAM *pbe=0;
    BIO *bp;
    char pass[100];
    int passlen;
    X509 *cert=NULL;
    STACK_OF(X509) *ca=NULL;
    EVP_PKEY *pkey=NULL;
    fp=fopen("timeserver.pfx","rb");
    len=fread(buf,1,10000,fp);
    fclose(fp);
    OpenSSL_add_all_algorithms();
    bp=BIO_new(BIO_s_file());
    BIO_set_fp(bp,stdout,BIO_NOCLOSE);
    p=buf;
    d2i_PKCS12(&p12,&p,len);
    printf("input password : \n");
    scanf("%s",pass);
    ret=PKCS12_parse(p12,pass,&pkey,&cert,&ca);
    if(ret!=1)
    {
        printf("err\n");
        return 0;
    }
    /* 私钥写入文件 */
    p=buf;
    len=i2d_PrivateKey(pkey,&p);
    fp=fopen("prikey.cer","wb");
    fwrite(buf,1,len,fp);
    fclose(fp);
    /* 修改密码 */
    ret=PKCS12_newpass(p12,pass,"test");
    fp=fopen("newpass.pfx","wb");
    ret=i2d_PKCS12_fp(fp,p12);
    fclose(fp);
    /* version */
    printf("version : %d\n",ASN1_INTEGER_get(p12->version));
    /* PKCS12_MAC_DATA */
    printf("PKCS12_MAC_DATA sig :\n");
    X509_SIG_print(bp,p12->mac->dinfo);
    printf("salt : \n");
    i2a_ASN1_STRING(bp,p12->mac->salt,1);
    printf("iter : %d\n",ASN1_INTEGER_get(p12->mac->iter));
    /* p7s */
    p7s=PKCS12_unpack_authsafes(p12);
    num=sk_PKCS7_num(p7s);

    for(i=0;i<num;i++)
    {
        one=sk_PKCS7_value(p7s,i);
        if(PKCS7_type_is_data(one))
        {
            bags = PKCS12_unpack_p7data(one);
            count=sk_PKCS12_SAFEBAG_num(bags);
            for(j=0;j<count;j++)
            {
                bag=sk_PKCS12_SAFEBAG_value(bags,j);
                PKCS12_SAFEBAG_print(bp,bag);
            }
        }
        else if(PKCS7_type_is_encrypted(one))
        {
back:
            printf("\ninput password :\n");
            scanf("%s",pass);
            passlen=strlen(pass);
            bags = PKCS12_unpack_p7encdata(one,pass,passlen);
            if(bags==NULL)
            goto back;
            printf("passwod is :%s\n",pass);
            count=sk_PKCS12_SAFEBAG_num(bags);
            for(j=0;j<count;j++)
            {
                bag=sk_PKCS12_SAFEBAG_value(bags,j);
                PKCS12_SAFEBAG_print(bp,bag);
            }
        }
    }
    BIO_free(bp);
    sk_PKCS7_pop_free(p7s,PKCS7_free);
    PKCS12_free(p12);
    return 0;
}




