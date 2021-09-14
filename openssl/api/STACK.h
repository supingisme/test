/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
//堆栈是一种先进后出的数据结构。openssl 大量采用堆栈来存放数据。它实现了一
//个通用的堆栈，可以方便的存储任意数据。它实现了许多基本的堆栈操作，主要有：堆
//栈拷贝(sk_dup)、构建新堆栈（sk_new_null，sk_new）、插入数据（sk_insert）、删除数
//据（sk_delete）、查找数据（sk_find，sk_find_ex）、入栈（sk_push）、出栈（sk_pop）、
//获取堆栈元素个数（sk_num）、获取堆栈值（sk_value）、设置堆栈值（sk_set）和堆栈
//排序（sk_sort）。




typedef struct stack_st {
    int num;
    char **data;
    int sorted;
    int num_alloc;
    int (*comp) (const void *, const void *);
} _STACK;                       /* Use STACK_OF(...) instead */

//各项意义如下：
//num: 堆栈中存放数据的个数。
//data: 用于存放数据地址，每个数据地址存放在data[0]到data[num-1]中。
//sorted: 堆栈是否已排序，如果排序则值为1，否则为0，堆栈数据一般是无序的，只
//有当用户调用了sk_sort 操作，其值才为1。
//comp: 堆栈内存放数据的比较函数地址，此函数用于排序和查找操作；当用户生成一
//个新堆栈时，可以指定comp 为用户实现的一个比较函数；或当堆栈已经存在
//时通过调用sk_set_cmp_func 函数来重新指定比较函数。
//注意，用户不需要调用底层的堆栈函数(sk_sort、sk_set_cmp_func 等)，而是调用他通过
//宏实现的各个函数。


#define M_sk_num(sk)            ((sk) ? (sk)->num:-1)
#define M_sk_value(sk,n)        ((sk) ? (sk)->data[n] : NULL)

int sk_num(const _STACK *);
void *sk_value(const _STACK *, int);

void *sk_set(_STACK *, int, void *);

_STACK *sk_new(int (*cmp) (const void *, const void *));
_STACK *sk_new_null(void);
void sk_free(_STACK *);
void sk_pop_free(_STACK *st, void (*func) (void *));
_STACK *sk_deep_copy(_STACK *, void *(*)(void *), void (*)(void *));
int sk_insert(_STACK *sk, void *data, int where);
void *sk_delete(_STACK *st, int loc);
void *sk_delete_ptr(_STACK *st, void *p);
int sk_find(_STACK *st, void *data);
int sk_find_ex(_STACK *st, void *data);
int sk_push(_STACK *st, void *data);
int sk_unshift(_STACK *st, void *data);
void *sk_shift(_STACK *st);
void *sk_pop(_STACK *st);
void sk_zero(_STACK *st);
int (*sk_set_cmp_func(_STACK *sk, int (*c) (const void *, const void *)))(const void *, const void *);
_STACK *sk_dup(_STACK *st);
void sk_sort(_STACK *st);
int sk_is_sorted(const _STACK *st);

