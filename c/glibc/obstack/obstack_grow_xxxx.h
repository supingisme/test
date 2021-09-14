#include<obstack.h>


void obstack_grow (struct obstack *obstack_ptr, void *data, int size);
//添加一个初始化的空间，类似与obstack_copy

void obstack_grow0 (struct obstack *obstack_ptr, void *data, int size);
//obstack_grow类似与obstack_copy, 那obstack_grow0你说类似与谁？;

void  obstack_lgrow (struct obstack *obstack_ptr, char c);
//一次添加一个字符（字节）

void    obstack_ptr_grow (struct obstack *obstack_ptr, void *data);
//一次添加一个指针。。。大小为（sizeof(void *)

void obstack_int_grow (struct obstack *obstack_ptr, int data);
//一次添加一个int型数据，大小为sizeof(int)


