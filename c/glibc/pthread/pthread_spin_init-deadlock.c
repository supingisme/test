#include <stdio.h>
#include <pthread.h>

int pthread_spin_destroy(pthread_spinlock_t *lock);
int pthread_spin_init(pthread_spinlock_t *lock, int pshared);

pthread_t thread;
pthread_spinlock_t spin_lock;

void *routine(void *arg)
{
	sleep(1);
	pthread_spin_lock(&spin_lock);
}

int main()
{
	pthread_spin_init(&spin_lock, PTHREAD_PROCESS_PRIVATE);	

	pthread_create(&thread, NULL, routine, NULL);

	pthread_spin_lock(&spin_lock);

	while(1);
}
