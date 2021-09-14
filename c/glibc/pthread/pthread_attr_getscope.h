//pthread_attr_setscope,  pthread_attr_getscope  -  set/get contention scope attribute in thread attributes
//object
//
//SYNOPSIS
#include <pthread.h>

//3.    线程的作用域：
                               
//函数pthread_attr_setscope和pthread_attr_getscope分别
//用来设置和得到线程的作用域。       
int pthread_attr_setscope(pthread_attr_t *attr, int scope);
int pthread_attr_getscope(pthread_attr_t *attr, int *scope);

//Compile and link with -pthread.
//参数：
//                    attr               线程属性变量
//                    scope         线程的作用域       
//            若成功返回0，若失败返回-1。
//           
//            作用域控制线程是否在进程内或在系统级上竞争资源，可能的值是
//            PTHREAD_SCOPE_PROCESS（进程内竞争资源）
//            PTHREAD_SCOPE_SYSTEM   （系统级竞争资源）。

