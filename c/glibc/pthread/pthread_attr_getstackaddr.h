//5.    线程堆栈的地址           

#include <pthread.h>
int pthread_attr_getstackaddr(const pthread_attr_t *attr,void **stackaddf);
int pthread_attr_setstackaddr(pthread_attr_t *attr,void *stackaddr);
//参数：attr               线程属性变量
//        stackaddr     堆栈地址           
//若成功返回0，若失败返回-1。
//
//注意：pthread_attr_getstackaddr已经过期，现在使用的是：pthread_attr_getstack
