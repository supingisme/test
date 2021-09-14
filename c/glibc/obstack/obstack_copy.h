#include<obstack.h>

void * obstack_copy(struct obstack *obstack_ptr, void *address, int size);
//使用从地址address开始复制size大小的数据初始化，新申请的object内存大小也为size

void *obstack_copy0(struct obstack *obstack_ptr, void *address, int size);
//同obstack_copy但结尾处额外添加一个空字符，在复制以NULL结尾的字符串时很方便。

