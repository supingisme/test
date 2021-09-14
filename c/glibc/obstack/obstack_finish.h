
#include<obstack.h>

//在growing object中最重要的函数是obstack_finish, 
//因为只有调用了本函数之后才会返回growing object 的最终地址。

void *obstack_finish (struct obstrack *obstrack_ptr);

