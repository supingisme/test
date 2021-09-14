#include <openssl/err.h>
#include <openssl/bn.h>

int mycb(const char *a,size_t b,void *c)
{
    printf("my print : %s\n",a);
    return 0;
}
int main()
{
    BIO *berr;
    unsigned long err;
    const char *file,*data,*efunc,*elib,*ereason,*p;
    int line,flags;
    char estring[500];
    FILE *fp;
    /*
    ERR_load_crypto_strings();
    */
    ERR_load_BIO_strings();
    ERR_clear_error();
    berr=BIO_new(BIO_s_file());
    BIO_set_fp(berr,stdout,BIO_NOCLOSE);
    BIO_new_file("no.exist","r");
    err=ERR_peek_last_error();
    err=ERR_peek_last_error_line(&file,&line);
    printf("ERR_peek_last_error_line err : %ld,file : %s,line: %d\n",err,file,line);
    err=ERR_peek_last_error_line_data(&file,&line,&data,&flags);
    printf("ERR_peek_last_error_line_data err: %ld,file :%s,line :%d,data :%s\n",err,file,line,data);
    err=ERR_peek_error();
    printf("ERR_peek_error err: %ld\n",err);
    err=ERR_peek_error_line(&file,&line);
    printf("ERR_peek_error_line err : %ld,file : %s,line: %d\n",err,file,line);
    err=ERR_peek_error_line_data(&file,&line,&data,&flags);
    printf("ERR_peek_error_line_data err : %ld,file :%s,line :%d,data :%s\n",err,file,line,data);
    err = ERR_get_error_line_data(&file,&line,&data,&flags);
    printf("ERR_get_error_line_data err : %ld,file :%s,line :%d,data :%s\n",err,file,line,data);
    if(err!=0)
    {
        p=ERR_lib_error_string(err);
        printf("ERR_lib_error_string : %s\n",p);
    }
    err=ERR_get_error();
    if(err!=0)
    {
        printf("ERR_get_error err : %ld\n",err);
        efunc=ERR_func_error_string(err);
        printf("err func : %s\n",efunc);
        elib=ERR_lib_error_string(err);
        printf("err lib : %s\n",efunc);
        ereason=ERR_reason_error_string(err);
        printf("err reason : %s\n",efunc);
        efunc=ERR_func_error_string(err);
        printf("err func : %s\n",efunc);
        elib=ERR_lib_error_string(err);
        printf("err lib : %s\n",efunc);
        ereason=ERR_reason_error_string(err);
        printf("err reason : %s\n",efunc);
        ERR_error_string(err,estring);
        printf("ERR_error_string : %s\n",estring);
        ERR_error_string_n(err,estring,sizeof(estring));
        printf("ERR_error_string_n : %s\n",estring);
    }
    err=ERR_get_error_line(&file,&line);
    printf("err file :%s , err line : %d\n",file,line);
    ERR_print_errors(berr);
    BIO_new_file("no.exist2","r");
    fp=fopen("err.log","w");
    ERR_print_errors_fp(fp);
    fclose(fp);
    BIO_new_file("no.exist3","r");
    ERR_print_errors_cb(mycb,NULL);
    ERR_put_error(ERR_LIB_BN,BN_F_BNRAND,BN_R_BIGNUM_TOO_LONG,__FILE__,
    line);
    ERR_print_errors(berr);
    ERR_load_BN_strings();
    ERR_put_error(ERR_LIB_BN,BN_F_BNRAND,BN_R_BIGNUM_TOO_LONG,__FILE__,line);
    ERR_print_errors(berr);
    ERR_put_error(ERR_LIB_BN,BN_F_BNRAND,BN_R_BIGNUM_TOO_LONG,__FILE__,line);
    ERR_set_error_data("set date test!\n",ERR_TXT_STRING);
    err=ERR_set_mark();
    ERR_print_errors(berr);
    ERR_free_strings();
    BIO_free(berr);
    return 0;
}
//# ./a.out 
//ERR_peek_last_error_line err : 537317504,file : bss_file.c,line: 182
//ERR_peek_last_error_line_data err: 537317504,file :bss_file.c,line :182,data :
//ERR_peek_error err: 33558530
//ERR_peek_error_line err : 33558530,file : bss_file.c,line: 175
//ERR_peek_error_line_data err : 33558530,file :bss_file.c,line :175,data :fopen('no.exist','r')
//ERR_get_error_line_data err : 33558530,file :bss_file.c,line :175,data :fopen('no.exist','r')
//ERR_lib_error_string : system library
//ERR_get_error err : 537317504
//err func : BIO_new_file
//err lib : BIO_new_file
//err reason : BIO_new_file
//err func : BIO_new_file
//err lib : BIO_new_file
//err reason : BIO_new_file
//ERR_error_string : error:2006D080:BIO routines:BIO_new_file:no such file
//ERR_error_string_n : error:2006D080:BIO routines:BIO_new_file:no such file
//err file :bss_file.c , err line : 175
//my print : 140625413380016:error:02001002:system library:fopen:No such file or directory:bss_file.c:175:fopen('no.e
//xist3','r')
//140625413380016:error:2006D080:BIO routines:BIO_new_file:no such file:bss_file.c:182:
//140625413380016:error:0307F072:bignum routines:func(127):reason(114):err/demo.c:175:
//140625413380016:error:0307F072:bignum routines:BNRAND:bignum too long:err/demo.c:175:
//140625413380016:error:0307F072:bignum routines:BNRAND:bignum too long:err/demo.c:175:set date test!

