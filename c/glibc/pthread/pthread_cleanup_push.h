//pthread_cleanup_push, pthread_cleanup_pop - push and pop thread cancellation clean-up handlers
//											推和弹出线程取消清理处理程序
//SYNOPSIS
#include <pthread.h>

//推和弹出线程取消清理处理程序
void pthread_cleanup_push(void (*routine)(void *),
                         void *arg);
void pthread_cleanup_pop(int execute);

//Compile and link with -pthread.

