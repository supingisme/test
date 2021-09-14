#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include "aioperf_manager.h"
#include "aioperf_conf.h"




/*   É¾³ý×ó±ßµÄ¿Õ¸ñ   */
int
aioperf_conf_del_lspace(char * szOutput, const char *szInput)
{
    if (!szInput || !szOutput || szOutput == szInput) {
        printf("conf del lspace error\n");
        return AIOPERF_ERROR;
    }

    for (; *szInput != '\0' && isspace(*szInput); ++szInput) {
        ;
    }

    strcpy(szOutput, szInput);

    return AIOPERF_OK;

}

 

/*   É¾³ýÓÒ±ßµÄ¿Õ¸ñ   */
int
aioperf_conf_del_rspace(char *szOutput, const char *szInput)
{
    char *p = NULL;

    if (!szInput || !szOutput || szOutput == szInput) {
        printf("conf del lspace error\n");
        return AIOPERF_ERROR;
    }

    strcpy(szOutput, szInput);

    for(p = szOutput + strlen(szOutput) - 1; p >= szOutput && isspace(*p); --p){
        ;
    }

    *(++p) = '\0';

    return AIOPERF_OK;
}

 

/*   É¾³ýÁ½±ßµÄ¿Õ¸ñ   */
int
aioperf_conf_del_aspace(char * szOutput, const char * szInput)
{
    char *p = NULL;

    if (!szInput || !szOutput) {
        printf("del all space error\n");
        return AIOPERF_ERROR;
    }

    aioperf_conf_del_lspace(szOutput, szInput);

    for (p = szOutput + strlen(szOutput) - 1;p >= szOutput && isspace(*p); --p){
        ;
    }

    *(++p) = '\0';

    return AIOPERF_OK;
}


int 
aioperf_conf_get_val(char *profile, char *AppName, char *KeyName, 
    unsigned int *val )
{
    char    appname[32];
    char    keyname[32];
    char   *buf;
    char   *c;
    char    buf_i[KEYVALLEN];
    char    buf_o[KEYVALLEN];
    FILE   *fp;
    int     found=0;
    char    keyval[KEYVALLEN] = "\0";

    if( (fp=fopen( profile,"r" ))==NULL ){
        printf( "openfile [%s] error [%s]\n",profile,strerror(errno) );
        return AIOPERF_ERROR;
    }

    fseek( fp, 0, SEEK_SET );

    aioperf_memory_set( appname, 0, sizeof(appname) );

    sprintf( appname,"[%s]", AppName );

    while ( !feof(fp) && fgets( buf_i, KEYVALLEN, fp )!=NULL ) {
        aioperf_conf_del_lspace(buf_o, buf_i);
        if( strlen(buf_o) <= 0 ) {
            continue;
        }

        buf = NULL;

        buf = buf_o;

        if( found == 0 ){
            if( buf[0] != '[' ) {
                continue;
            } else if ( strncmp(buf,appname,strlen(appname))==0 ){
                found = 1;
                continue;
            }
        } else if( found == 1 ){

            if( buf[0] == '#' ){
                continue;
            } else if ( buf[0] == '[' ) {

                break;

            } else {
                if( (c = (char*)strchr(buf, '=')) == NULL ) {
                continue;
                }

                aioperf_memory_set( keyname, 0, sizeof(keyname) );

                sscanf( buf, "%[^=|^ |^\t]", keyname );

                if( strcmp(keyname, KeyName) == 0 ){

                    sscanf( ++c, "%[^\n]", keyval );

                    char *KeyVal_o = (char *)aioperf_memory_alloc(strlen(keyval) + 1);

                    if(KeyVal_o != NULL){

                        aioperf_memory_set(KeyVal_o, 0, strlen(keyval) + 1);

                        aioperf_conf_del_aspace(KeyVal_o, keyval);

                        if(KeyVal_o && strlen(KeyVal_o) > 0)

                        //strcpy(keyval, KeyVal_o);
                        *val = atoi(KeyVal_o);
                        
                        aioperf_memory_free(KeyVal_o);

                        KeyVal_o = NULL;

                    }

                    found = 2;

                    break;

                } else {

                    continue;
                }
            }
        }
    }

    fclose( fp );

    if( found == 2 ) {
        return AIOPERF_OK;
    }

    return AIOPERF_ERROR;
}



int
aioperf_conf_repository_init(aioperf_manager_t *mgr, char *conf_file_name)
{
    char                    buf[100];
    unsigned int            file_size;
    unsigned int            percent;
    unsigned int            i;
    aioperf_conf_file_t    *file_t = NULL;
    aioperf_conf_info_t    *read_conf = NULL;
    aioperf_conf_info_t    *write_conf = NULL;
    aioperf_pool_t         *pool = NULL;

        
    if (!mgr || !conf_file_name) {
        return AIOPERF_ERROR;
    }

    pool = mgr->pool;
    
    if (!(read_conf = (aioperf_conf_info_t *)aioperf_memory_pool_alloc(
        mgr->pool, sizeof(aioperf_conf_info_t)))) {
        printf("pool alloc error\n");
        return AIOPERF_ERROR;
    }
    
    mgr->read_repository.conf_info = read_conf;

    if (!(write_conf = (aioperf_conf_info_t *)aioperf_memory_pool_alloc(
        mgr->pool, sizeof(aioperf_conf_info_t)))) {
        printf("pool alloc error\n");
        return AIOPERF_ERROR;
    }

    mgr->write_repository.conf_info = write_conf;

    if (aioperf_conf_get_val(conf_file_name, "read_conf", "read_file_num", 
        &read_conf->file_num) != AIOPERF_OK) {
        printf("read_file_num error\n");
        //return AIOPERF_ERROR;
    }

    if (read_conf->file_num >= MAX_FILE_NUM) {
        read_conf->file_num = MAX_FILE_NUM;
    }
    
    if (read_conf->file_num <= 0) {
        printf("READ: file is 0\n");
        goto write_conf;
    }
    
    read_conf->conf_file = NULL;

    for (i = 0;; i++) {
        aioperf_memory_set(buf, 0, 100);
        snprintf(buf, 100, "read_file%d_size", i + 1);
        
        if (aioperf_conf_get_val(conf_file_name, "read_conf", buf, &file_size) 
            != AIOPERF_OK) {
            break;
        }
        
        aioperf_memory_set(buf, 0, 100);
        snprintf(buf, 100, "read_file%d_percent", i + 1);
        
        if (aioperf_conf_get_val(conf_file_name, "read_conf", buf, &percent) 
            != AIOPERF_OK) {
            break;
        }

        file_t = (aioperf_conf_file_t *)aioperf_memory_pool_alloc(pool,
            sizeof(aioperf_conf_file_t));
        file_t->file_size = file_size;
        file_t->percent = percent;
        file_t->next = NULL;

        file_t->next = read_conf->conf_file;
        read_conf->conf_file = file_t;

    }

    printf("READ: %d file class\n", i);

    if (aioperf_conf_get_val(conf_file_name, "read_conf", "read_buf_size", 
        &read_conf->buf_size) != AIOPERF_OK) {
        printf("read_buf_size error\n");
        //return AIOPERF_ERROR;
    }

    if (read_conf->buf_size != 0 && 
        !(mgr->read_repository.buf = (char *)aioperf_memory_pool_alloc(pool, 
        read_conf->buf_size))) {
        printf("alloc error\n");
        return AIOPERF_ERROR;
    }

write_conf:
    if (aioperf_conf_get_val(conf_file_name, "write_conf", "write_file_num", 
        &write_conf->file_num) != AIOPERF_OK) {
        printf("write_file_num error\n");
        //return AIOPERF_ERROR;
    }

    if (write_conf->file_num >= MAX_FILE_NUM) {
        write_conf->file_num = MAX_FILE_NUM;
    }
    
    if (write_conf->file_num <= 0) {
        printf("WRITE: file is 0\n");
        if (read_conf->file_num <= 0) {
            return AIOPERF_ERROR;
        }
        return AIOPERF_OK;
    }

    write_conf->conf_file = NULL;
    
    for (i = 0;; i++) {
        aioperf_memory_set(buf, 0, 100);
        snprintf(buf, 100, "write_file%d_size", i + 1);
        
        if (aioperf_conf_get_val(conf_file_name, "write_conf", buf, &file_size) 
            != AIOPERF_OK) {
            break;
        }
        
        aioperf_memory_set(buf, 0, 100);
        snprintf(buf, 100, "write_file%d_percent", i + 1);
        
        if (aioperf_conf_get_val(conf_file_name, "write_conf", buf, &percent) 
            != AIOPERF_OK) {
            break;
        }

        file_t = (aioperf_conf_file_t *)aioperf_memory_pool_alloc(pool,
            sizeof(aioperf_conf_file_t));
        file_t->file_size = file_size;
        file_t->percent = percent;
        file_t->next = NULL;
        
        file_t->next = write_conf->conf_file;
        write_conf->conf_file = file_t;

    }

    printf("WRITE: %d file class\n", i);


    if (aioperf_conf_get_val(conf_file_name, "write_conf", "write_buf_size", 
        &write_conf->buf_size) != AIOPERF_OK) {
        printf("write_buf_size error\n");
        //return AIOPERF_ERROR;
    }

    if (write_conf->buf_size !=0 && 
        !(mgr->write_repository.buf = (char *)aioperf_memory_pool_alloc(pool, 
        write_conf->buf_size))) {
        printf("alloc error\n");
        return AIOPERF_ERROR;
    }

    if (write_conf->buf_size != 0) {
        aioperf_memory_set(mgr->write_repository.buf, '1', write_conf->buf_size);
    }

    if ((write_conf->file_num <= 0 || write_conf->buf_size <= 0) &&
        (read_conf->file_num <= 0 || read_conf->buf_size <= 0)) {
        printf("conf param error\n");
        return AIOPERF_ERROR;
    }
    return AIOPERF_OK;
}


int
aioperf_conf_mgr_init(aioperf_manager_t *mgr, char *conf_file_name)
{
    if (aioperf_conf_get_val(conf_file_name, "public", "aio_thread_num",
        &mgr->io_thread_num) != AIOPERF_OK) {
        printf("thread num not set, use default(8)\n");
        mgr->io_thread_num = 8;
    }

    return AIOPERF_OK;
}


