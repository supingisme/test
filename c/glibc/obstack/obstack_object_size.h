#include<obstack.h>


//在growing object中最重要的函数是obstack_finish, 因为只有调用了本函数之后才会返回growing object 的最终地址。

//void *obstack_finish (struct obstrack *obstrack-ptr)
//如果你想获取growing object当前大小，可以使用obstack_object_size

int obstack_object_size (struct obstack *obstrack_ptr);
//只能用在obstack_finish之前，否则只会返回0
//如果你想取消一个正在增长的对象，必须先结束他，然后再释放。示例如下：
//
//obstack_free (obstack_ptr, obstack_finish (obstack_ptr))
//上面的函数在添加数据时会检查是否由足够的空间。如果你只增加一丁点的空间，检查这一步骤显然是多余的。
//我们可以省略这一步骤，更快的growing。这里关于growing object额外在介绍一个函数：
//
//int obstack_room (struct obstack *obstack-ptr)
////返回可以安全添加的字节数
//其余的快速添加函数只需要在之前的growing object函数添加后缀_fast即可
//（如果不清楚可以查看GNU C 关于这部分的介绍）

