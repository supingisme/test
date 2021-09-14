#include<obstack.h>


//以下函数用于获取obstack的状态：

//void * obstack_base (struct obstack *obstack_ptr);
////返回正在增长的对象的假定起始地址。为啥是假定呢，因为如果你增长的过大，
////当前chunk的空间不够，obstack就会新创建一个chunk，这样地址就变了。

void *obstack_next_free (struct obstack *obstack_ptr);
//返回当前chunk未被占用的第一个字节的地址

//int obstack_object_size (struct obstack *obstack_ptr);
////返回当前growing object的大小。等同与：
////obstack_next_free (obstack-ptr) -obstack_base (obstack-ptr)


