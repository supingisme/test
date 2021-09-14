#include<obstack.h>

int obstack_init(struct obstack *obstack_ptr);

//obstack_init实际上是一个宏实现。obstack_init会自动调用obstack_chunk_alloc函数来申请chunk，
//注意这还是个宏，需要你指定这个宏指向的函数。
//如果内存申请失败了会调用obstack_alloc_failed_handler指向的函数，没错依旧是宏。
//如果chunk里面的对象都被释放了，obstack_chunk_free指向的函数被用来返回chunk占用的空间。
//目前版本的obstack_init永远只返回1（之前的版本会在失败的时候返回0）

