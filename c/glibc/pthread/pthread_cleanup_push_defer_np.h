#include <pthread.h>

//push and pop thread cancellation clean-up handlers while saving cancelability type
void pthread_cleanup_push_defer_np(void (*routine)(void *), void *arg);
void pthread_cleanup_pop_restore_np(int execute);

//Compile and link with -pthread.

