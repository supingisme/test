#include <pthread.h>

//pthread_equal - compare thread IDs
int pthread_equal(pthread_t t1, pthread_t t2);
//RETURN VALUE
//       If the two thread IDs are equal, pthread_equal() returns a nonzero value; otherwise, it returns 0.

//Compile and link with -pthread.

