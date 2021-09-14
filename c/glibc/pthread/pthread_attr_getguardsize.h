//pthread_attr_setguardsize,  pthread_attr_getguardsize - set/get guard size attribute in thread attributes
//object

#include <pthread.h>
//函数pthread_attr_getguardsize和pthread_attr_setguardsize分别用来设置和得
//到线程栈末尾的警戒缓冲区大小。
//
//#include <pthread.h>                   
//int pthread_attr_getguardsize(const pthread_attr_t *restrict attr,size_t *restrict
//guardsize);
//int pthread_attr_setguardsize(pthread_attr_t *attr ,size_t *guardsize);
//若成功返回0，若失败返回-1。
//
//值得注意：
//            线程属性guardsize控制着线程栈末尾之后以避免栈溢出的扩展内存
//            大小。这个属性默认设置为PAGESIZE个字节。可以把guardsize线
//            程属性设为0，从而不允许属性的这种特征行为发生：在这种情况
//            下不会提供警戒缓存区。同样地，如果对线程属性stackaddr作了
//            修改，系统就会认为我们会自己管理栈，并使警戒栈缓冲区机制无
//            效，等同于把guardsize线程属性设为0。

int pthread_attr_setguardsize(pthread_attr_t *attr, size_t guardsize);
int pthread_attr_getguardsize(pthread_attr_t *attr, size_t *guardsize);

//Compile and link with -pthread.

