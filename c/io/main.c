/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:37 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:37 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:21 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:57 CST. */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>

#define USR_CHMOD_ALL       S_IRUSR|S_IWUSR|S_IXUSR
#define GRP_CHMOD_ALL       S_IRGRP|S_IWGRP|S_IXGRP
#define OTH_CHMOD_ALL       S_IROTH|S_IWOTH|S_IXOTH
#define READ_CHMOD_ALL      S_IRUSR|S_IRGRP|S_IROTH
#define WRITE_CHMOD_ALL     S_IWUSR|S_IWGRP|S_IWOTH
#define EXECUTE_CHMOD_ALL   S_IXUSR|S_IXGRP|S_IXOTH
#define CHMOD_ALL           USR_CHMOD_ALL|GRP_CHMOD_ALL|OTH_CHMOD_ALL

int is_exist(const char *dirname)
{
    if(dirname == NULL)
    {
        printf("dirname is NULL\n");
        return -1;
    }
    return access(dirname, F_OK);
}

int is_readable(const char *dirname)
{
    if(dirname == NULL)
    {
        printf("dirname is NULL\n");
        return -1;
    }
    return access(dirname, R_OK);
}

int is_writeable(const char *dirname)
{
    if(dirname == NULL)
    {
        printf("dirname is NULL\n");
        return -1;
    }
    return access(dirname, W_OK);
}

int is_executable(const char *dirname)
{
    if(dirname == NULL)
    {
        printf("dirname is NULL\n");
        return -1;
    }
    return access(dirname, X_OK);
}

int add_read_permission(const char *dirname)
{
    if(dirname == NULL)
    {
        printf("dirname is NULL\n");
        return -1;
    }
    if(-1 == access(dirname, F_OK))
    {
        return -1;
    }
    else
    {
        return chmod(dirname, READ_CHMOD_ALL);
    }
}
int add_write_permission(const char *dirname)
{
    if(dirname == NULL)
    {
        printf("dirname is NULL\n");
        return -1;
    }
    if(-1 == access(dirname, F_OK))
    {
        return -1;
    }
    else
    {
        return chmod(dirname, WRITE_CHMOD_ALL);
    }
}

int add_execute_permission(const char *dirname)
{
    if(dirname == NULL)
    {
        printf("dirname is NULL\n");
        return -1;
    }
    if(-1 == access(dirname, F_OK))
    {
        return -1;
    }
    else
    {
        return chmod(dirname, EXECUTE_CHMOD_ALL);
    }
}

int add_usr_permission(const char *dirname)
{
    if(dirname == NULL)
    {
        printf("dirname is NULL\n");
        return -1;
    }
    if(-1 == access(dirname, F_OK))
    {
        return -1;
    }
    else
    {
        return chmod(dirname, USR_CHMOD_ALL);
    }
}

int add_grp_permission(const char *dirname)
{
    if(dirname == NULL)
    {
        printf("dirname is NULL\n");
        return -1;
    }
    if(-1 == access(dirname, F_OK))
    {
        return -1;
    }
    else
    {
        return chmod(dirname, GRP_CHMOD_ALL);
    }
}

int add_oth_permission(const char *dirname)
{
    if(dirname == NULL)
    {
        printf("dirname is NULL\n");
        return -1;
    }
    if(-1 == access(dirname, F_OK))
    {
        return -1;
    }
    else
    {
        return chmod(dirname, OTH_CHMOD_ALL);
    }
}

int add_all_permission(const char *dirname)
{
    if(dirname == NULL)
    {
        printf("dirname is NULL\n");
        return -1;
    }
    if(-1 == access(dirname, F_OK))
    {
        return -1;
    }
    else
    {
        return chmod(dirname, USR_CHMOD_ALL|GRP_CHMOD_ALL|OTH_CHMOD_ALL);
    }
}

int create_dir(const char *dirname)
{
    if(dirname == NULL)
    {
        printf("dirname is NULL\n");
        return -1;
    }
    
    char tmp[strlen(dirname) + 100];
    
    if(-1 == access(dirname, F_OK))
    {
        sprintf(tmp, "mkdir %s", dirname);
        system(tmp);
        printf("%s\n", tmp);
        return 0;
    }
    else
    {
        printf("%s already exist.\n", dirname);
        return 0;
    }

    return -1;
}

int delete_dir(const char *dirname)
{
    if(dirname == NULL)
    {
        printf("dirname is NULL\n");
        return -1;
    }
    
    char tmp[strlen(dirname) + 100];
    if(-1 == access(dirname, F_OK))
    {
        printf("%s don't exist.\n", dirname);
        return -1;
    }
    else
    {
        sprintf(tmp, "rm -r %s", dirname);
        system(tmp);
        printf("%s\n", tmp);
        return 0;
    }
    return -1;
}

int copy_file(const char *filename, const char *target_dir)
{
    if(filename == NULL || target_dir == NULL)
    {
        printf("invalid arg pointer.\n");
        return -1;
    }
    
    struct stat st;
    stat(target_dir, &st);
    
    char tmp[strlen(filename) + strlen(target_dir) + 100];
    
    if(S_ISDIR(st.st_mode))
    {
        if(-1 == access(target_dir, F_OK))
        {
            printf("%s doesn't exist.\n", target_dir);
            return -1;
        }
        else
        {
            if(-1 == access(target_dir, W_OK|R_OK|X_OK))
            {
                chmod(target_dir, CHMOD_ALL);
            }
            else
            {
                if(0 == access(filename, F_OK))
                {
                    stat(filename, &st);
                    if(S_ISDIR(st.st_mode))
                    {
                        sprintf(tmp, "cp -a %s %s", filename, target_dir);
                    }
                    else
                    {
                        sprintf(tmp, "cp %s %s", filename, target_dir);
                    }
                    system(tmp);
                    printf("%s\n", tmp);
                    return 0;
                }
                else
                {
                    printf("%s doesn't exist.\n", filename);
                    return -1;
                }
            }
        }
    }
    else
    {
        printf("%s is not a directory.\n", target_dir);
        return -1;
    }
}

int delete_file(const char *filename, ...)
{
    if(filename == NULL)
    {
        printf("invalid pointer.\n");
        return -1;
    }
    
    
    struct stat st;
    char tmp[strlen(filename) + 100];
    
    if(-1 == access(filename, F_OK))
    {
        printf("%s doesn't exist.\n", filename);
        return -1;
    }
    else
    {
        if(-1 == access(filename, W_OK|R_OK|X_OK))
        {
            chmod(filename, CHMOD_ALL);
        }
        else
        {
            stat(filename, &st);
            if(S_ISDIR(st.st_mode))
            {
                sprintf(tmp, "rm -r %s", filename);
            }
            else
            {
                sprintf(tmp, "rm %s", filename);
            }
            system(tmp);
            printf("%s\n", tmp);
            
            /*处理 "..." 内容*/
            va_list arg;
            va_start(arg, filename);
            char *filenames;
            while(1)
            {
                filenames = va_arg(arg, char *);
                if(0 == access(filenames, F_OK))
                {
                    delete_file(filenames);
                }
                else
                {
                    break;
                }
            }
            va_end(arg);
            
            return 0;
        }
    }
}

int main()
{
    //create_dir("RongTao");
    //create_dir("RongTao1");
    //sleep(3);
    create_dir("b.out");
    create_dir("RongTao1");
    copy_file("b.out", "RongTao1");
    delete_file("2/1");
    delete_file("RongTao1/b.out", "a.out", "b.out", "RongTao1", "1/1", "1", "3");
    return 0;
}