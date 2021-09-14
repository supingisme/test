#include<obstack.h>


int obstack_room (struct obstack *obstack_ptr);
////返回可以安全添加的字节数
//其余的快速添加函数只需要在之前的growing object函数添加后缀_fast即可
//（如果不清楚可以查看GNU C 关于这部分的介绍）

