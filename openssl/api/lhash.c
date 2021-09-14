/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <string.h>
#include <openssl/lhash.h>

typedef struct Student_st
{
    char name[20];
    int age;
    char otherInfo[200];
}Student;
static int Student_cmp(const void *a, const void *b)
{
    char *namea=((Student *)a)->name;
    char *nameb=((Student *)b)->name;
    return strcmp(namea,nameb);
}
/* 打印每个值*/
static void PrintValue(Student *a)
{
    printf("name :%s\n",a->name);
    printf("age :%d\n",a->age);
    printf("otherInfo : %s\n",a->otherInfo);
}
static void PrintValue_arg(Student *a,void *b)
{
    int flag=0;
    flag=*(int *)b;
    printf("用户输入参数为:%d\n",flag);
    printf("name :%s\n",a->name);
    printf("age :%d\n",a->age);
    printf("otherInfo : %s\n",a->otherInfo);
}
int main()
{
    int flag=11;

    _LHASH *h;
    
    Student s1={"zcp",28,"hu bei"},
            s2={"forxy",28,"no info"},
            s3={"skp",24,"student"},
            s4={"zhao_zcp",28,"zcp's name"},
            *s5;
    
    void *data;
    h=lh_new(NULL,Student_cmp);
    if(h==NULL)
    {
        printf("err.\n");
        return -1;
    }
    data=&s1;
    lh_insert(h,data);
    data=&s2;
    lh_insert(h,data);
    data=&s3;
    lh_insert(h,data);
    data=&s4;
    lh_insert(h,data);
    
    /* 打印*/
    lh_doall(h,(LHASH_DOALL_FN_TYPE)PrintValue);
    lh_doall_arg(h,(LHASH_DOALL_ARG_FN_TYPE)PrintValue_arg,(void *)(&flag));
    
    data=lh_retrieve(h,(const void*)"skp");
    if(data==NULL)
    {
        printf("can not look up skp!\n");
        lh_free(h);
        return -1;
    }
    
    s5=data;
    
    printf("student name : %s\n",s5->name);
    printf("sutdent age : %d\n",s5->age);
    printf("student otherinfo : %s\n",s5->otherInfo);
    
    lh_free(h);
    
    getchar();
    return 0;
}


