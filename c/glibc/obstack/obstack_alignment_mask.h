#include<obstack.h>


//Obstack 里的数据对齐问题
int obstack_alignment_mask (struct obstack *obstack_ptr);
//宏展开后是一个左值。如果是函数实现，返回的是掩码。你给他复制也应该是掩码。
//掩码的值应该是2的n次方减一，换算后也就是说地址必须是2的n次方的倍数。
//如果你改变了掩码，只有下次申请object的时候才会生效
//（特例是growing object：立即生效，调用obstack_finish后就能看到效果了）

