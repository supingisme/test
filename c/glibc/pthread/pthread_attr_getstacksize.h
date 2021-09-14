#include <pthread.h>
//4.    线程堆栈的大小
//
//函数pthread_attr_setstackaddr和pthread_attr_getstackaddr分别用来设置和得
//到线程堆栈的位置。

int pthread_attr_getstacksize(const pthread_attr_t *,size_t * stacksize);
int pthread_attr_setstacksize(pthread_attr_t *attr ,size_t *stacksize);
//参数：attr                线程属性变量
//        stacksize        堆栈大小
//若成功返回0，若失败返回-1。 

