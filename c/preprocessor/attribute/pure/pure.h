#ifndef __PURE_H
#define __PURE_H 1

#if __GNUC_PREREQ (2,96)
# define __attribute_pure__ __attribute__ ((__pure__))
#else
# define __attribute_pure__
#endif

#endif //__PURE_H
//大致意思是这个函数这个函数没有副作用，当不需要它的返回值时，它可以被优化掉，
//但是我们自己的实现中是有打印输出的，所以造成声明和实现不一致。
//因为在第二个程序中，我们没有用到它的返回值，所以这个函数直接被删除掉了，才会出现上面的结果。
