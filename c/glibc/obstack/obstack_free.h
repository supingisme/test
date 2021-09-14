#include<obstack.h>

void obstack_free(struct obstack *obstack_ptr, void *object);
//如果object是空指针的话，所有的对象都被释放，留下一个未初始化的obstack,然后obstack库会自动释放chunk。
//如果你指定了object地址，那自这个object之后的所有对象都被释放。
//值得注意的是：如果你想释放所有object但同时保持obstack有效，可以指定第一个object的地址


