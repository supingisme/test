#include<obstack.h>


//以下函数用于获取obstack的状态：

void * obstack_base (struct obstack *obstack_ptr);
//返回正在增长的对象的假定起始地址。为啥是假定呢，因为如果你增长的过大，
//当前chunk的空间不够，obstack就会新创建一个chunk，这样地址就变了。

