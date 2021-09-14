#include <pthread.h>

//destroy and initialize condition variables
int pthread_cond_destroy(pthread_cond_t *cond);
int pthread_cond_init(pthread_cond_t * cond, const pthread_condattr_t * attr);


pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

