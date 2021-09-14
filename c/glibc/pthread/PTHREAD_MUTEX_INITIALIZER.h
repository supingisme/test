

pthread_mutex_t mutex;
pthread_mutex_init (&mutex, NULL);

/**
 *	Another simpler way to create a mutex with default attributes is to initialize it
 *	with the special value PTHREAD_MUTEX_INITIALIZER. No additional call to
 *	pthread_mutex_init is necessary.This is particularly convenient for global variables
 *	(and, in C++, static data members).The previous code fragment could equivalently
 *	have been written like this:
 */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


