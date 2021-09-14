//OBJ_bsearch
//用于从排序好的数据结构地址数组中用二分法查找数据。示例如下：
#include <openssl/objects.h>

typedef struct Student_st
{
    int age;
}Student;

int cmp_func(const void *a,const void *b)
{
    Student *x,*y;
    x=*(Student **)a;
    y=*(Student **)b;
    return x->age-y->age;
}
int main()
{
    int ret,num,size;
    ASN1_OBJECT *obj=NULL;
    char **addr,*p;
    Student a[6],**sort,**x;
    a[0].age=3;
    a[1].age=56;
    a[2].age=5;
    a[3].age=1;
    a[4].age=3;
    a[5].age=6;
    
    sort=(Student **)malloc(6*sizeof(Student *));
    sort[0]=&a[0];
    sort[1]=&a[1];
    sort[2]=&a[2];
    sort[3]=&a[3];
    sort[4]=&a[4];
    sort[5]=&a[5];
    qsort(sort,6,sizeof(Student *),cmp_func);
    obj=OBJ_nid2obj(NID_rsa);
    ret=OBJ_add_object(obj);
    if(ret==NID_undef)
    {
        printf("err");
    }
    else
    {
        printf("ok\n");
    }
    p=&a[4];
    addr=OBJ_bsearch(&p,(char *)sort,6,sizeof(Student *),cmp_func);//?????????????????
    x=(Student **)addr;
    printf("%d == %d\n",a[4].age,(*x)->age);
    return 0;
}

