#include <stdio.h>

#ifndef offsetof
#define offsetof(type, number) __builtin_offsetof(type, number)
#endif


#ifndef container_of
#define container_of(ptr, type, member) ({ \
        const typeof( ((type *)0)->member ) *__mptr = (typeof( ((type *)0)->member ) *)(ptr);	\
        (type *)( (char *)__mptr - offsetof(type, member) );})
#endif

/*
    在结构体放入struct list，然后可以用container_of接口轮询整个链表：荣涛 rongtao
*/
struct list {
    struct list *next, *prev;
};

struct A {
    int a;
    struct list ll;
};

struct A *next(struct A *a)
{
    return container_of(a->ll.next, struct A, ll);
}
struct A *prev(struct A *a)
{
    return container_of(a->ll.prev, struct A, ll);
}



/**
已知结构体type的成员member的地址ptr，求解结构体type的起始地址。
type的起始地址 = ptr - size      (这里需要都转换为char *，因为它为单位字节)。
*/
int main()
{
    struct A a1, a2, a3;

    a1.a = 1;
    a2.a = 2;
    a3.a = 3;
    
    a1.ll.next = &a2.ll;
    a1.ll.prev = &a3.ll;

    a2.ll.next = &a3.ll;
    a2.ll.prev = &a1.ll;

    a3.ll.next = &a1.ll;
    a3.ll.prev = &a2.ll;
    
    printf("%p, %p\n", container_of(&a1.ll, struct A, ll), &a1);

    struct A *pa = &a1;
    
    printf("%d\n", pa->a);

    pa = next(pa);
    printf("%d\n", pa->a);
    pa = next(pa);
    printf("%d\n", pa->a);
    pa = next(pa);
    printf("%d\n", pa->a);
    pa = next(pa);
    printf("%d\n", pa->a);

    
    return 0;
}




