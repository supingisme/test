#include <string.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
int main()
{
    X509 *x;
    BIO *b,*out;
    int ret,len,position,count;
    unsigned int mdl;
    unsigned char md[20];
    char buf[1024],*bufp,bytes[500];
    const EVP_MD *type;
    X509_NAME *xname,*xn;
    unsigned long hv=0;
    FILE *fp;
    ASN1_OBJECT *obj;
    X509_NAME_ENTRY *entry,*c=NULL,*c1;
    ASN1_STRING *str;
    /* cert.cer为PEM 格式的数字证书 */
    b=BIO_new_file("der.cer","r");
    if(b==NULL)
    {
        printf("can not open b64cert.cer!\n");
        return -1;
    }
    x=PEM_read_bio_X509(b,NULL,NULL,NULL);
    /* X509_NAME 函数 */
    /* X509_get_issuer_name,返回指针地址 */
    xname=X509_get_issuer_name(x);
    /* X509_get_subject_name,返回指针地址 */
    xname=X509_get_subject_name(x);
    /* X509_NAME_hash,将X509_NAME 数据结构中缓存的DER 编码值(放在
    bytes 中)MD5,其结果再做运算，注意xname->hash 此时的值无意义 */
    hv=X509_NAME_hash(xname);
    /* X509_NAME_print */
    out=BIO_new(BIO_s_file());
    BIO_set_fp(out,stdout,BIO_NOCLOSE);
    X509_NAME_print(out,xname,0);
    printf("\n");
    /* X509_NAME_print_ex_fp */
    fp=stdout;
    X509_NAME_print_ex_fp(fp,xname,0,XN_FLAG_SEP_MULTILINE);
    printf("\n\n");
    /* X509_NAME_print_ex,XN_FLAG_SEP_MULTILINE 表明个值打印时占一行
    */
    X509_NAME_print_ex(out,xname,0,XN_FLAG_SEP_MULTILINE);
    printf("\n");
    /* X509_NAME_get_text_by_NID */
    len=1024;
    ret=X509_NAME_get_text_by_NID(xname,NID_commonName,buf,len);
    printf("commonName : %s\n\n",buf);
    /* X509_NAME_get_text_by_OBJ */
    len=1024;
    obj=OBJ_nid2obj(NID_commonName);
    memset(buf,0,1024);
    ret=X509_NAME_get_text_by_OBJ(xname,obj,buf,len);
    printf("commonName : %s\n\n",buf);
    /* X509_NAME_get_index_by_NID */
    position=X509_NAME_get_index_by_NID(xname,NID_commonName,-1);
    entry=X509_NAME_get_entry(xname,position);
    printf("entry value : %s\n",entry->value->data);
    /* X509_NAME_ENTRY_get_data */
    str=X509_NAME_ENTRY_get_data(entry);
    /* X509_NAME_ENTRY_get_object */

    obj=X509_NAME_ENTRY_get_object(entry);
    /* X509_NAME_entry_count */
    count=X509_NAME_entry_count(xname);
    /* X509_NAME_get_index_by_OBJ */
    len=1024;
    memset(buf,0,1024);
    position=X509_NAME_get_index_by_OBJ(xname,obj,-1);
    entry=X509_NAME_get_entry(xname,position);
    printf("entry value : %s\n",entry->value->data);
    /* X509_NAME_digest */
    type=EVP_sha1();
    ret=X509_NAME_digest(x->cert_info->subject,type,md,&mdl);
    if(ret!=1)
    {
        printf("X509_NAME_digest err.\n");
        BIO_free(b);
        X509_free(x);
        return -1;
    }
    /* X509_name_cmp */
    ret=X509_name_cmp(x->cert_info->subject,x->cert_info->issuer);
    if(ret==0)
    {
        printf("subject == issuer\n");
    }
    else
    {
        printf("subject != issuer\n");
    }
    /* X509_NAME_oneline */
    len=1024;
    bufp=X509_NAME_oneline(x->cert_info->subject,buf,len);
    if(bufp==NULL)
    {
        printf("X509_NAME_oneline err\n");
    }
    else
    {
        printf("%s\n",buf);
    }
    /* 构造X509_NAME */
    xn=X509_NAME_new();
    strcpy(bytes,"openssl");
    len=strlen(bytes);
    /* X509_NAME_add_entry_by_txt */
    ret=X509_NAME_add_entry_by_txt(xn,"commonName",V_ASN1_UTF8STRING,bytes,len,0,-1);
    if(ret!=1)
    {
        printf("X509_NAME_add_entry_by_txt err.\n");
    }
    /* X509_NAME_add_entry_by_NID */
    strcpy(bytes,"china");
    len=strlen(bytes);
    ret=X509_NAME_add_entry_by_txt(xn,LN_countryName,V_ASN1_UTF8STRING,bytes,len,0,-1);
    if(ret!=1)
    {
        printf("X509_NAME_add_entry_by_txt err.\n");
    }
    /* X509_NAME_add_entry_by_OBJ */
    strcpy(bytes,"myou");
    len=strlen(bytes);
    obj=OBJ_nid2obj(NID_organizationalUnitName);
    ret=X509_NAME_add_entry_by_OBJ(xn,obj,V_ASN1_UTF8STRING,bytes,len,0,-1);
    if(ret!=1)
    {
        printf("X509_NAME_add_entry_by_OBJ err.\n");
    }
    /* X509_NAME_ENTRY_create_by_NID */
    strcpy(bytes,"myo");
    len=strlen(bytes);
    c=X509_NAME_ENTRY_create_by_NID(&c,NID_organizationName,V_ASN1_UTF8STRING,bytes,len);
    /* X509_NAME_add_entry */
    ret=X509_NAME_add_entry(xn,c,1,-1);
    if(ret!=1)
    {
        printf("X509_NAME_add_entry_by_OBJ err.\n");
    }
    /* X509_NAME_ENTRY_set_object */
    obj=OBJ_nid2obj(NID_localityName);
    c1=X509_NAME_ENTRY_new();
    ret=X509_NAME_ENTRY_set_object(c1,obj);
    if(ret!=1)
    {
        printf("X509_NAME_ENTRY_set_object err.\n");
    }
    strcpy(bytes,"mylocal");
    len=strlen(bytes);
    /* X509_NAME_ENTRY_set_data */
    ret=X509_NAME_ENTRY_set_data(c1,V_ASN1_UTF8STRING,bytes,len);
    if(ret!=1)
    {
        printf("X509_NAME_ENTRY_set_data err.\n");
    }
    ret=X509_NAME_add_entry(xn,c,2,-1);
    if(ret!=1)
    {
        printf("X509_NAME_add_entry_by_OBJ err.\n");
    }
    c1=X509_NAME_delete_entry(xn,2);
    
    /* X509_NAME_set */
    BIO_free(b);
    X509_free(x);
    return 0;
}

