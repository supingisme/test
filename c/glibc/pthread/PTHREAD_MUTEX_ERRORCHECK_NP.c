

/**
 *	By default, a GNU/Linux mutex is of the fast kind.To create a mutex of one
 *	of the other two kinds, first create a mutex attribute object by declaring a
 *	pthread_mutexattr_t variable and calling pthread_mutexattr_init on a
 *	pointer to it.Then set the mutex kind by calling pthread_mutexattr_setkind_np; the
 *	first argument is a pointer to the mutex attribute object, and the second is
 *	PTHREAD_MUTEX_RECURSIVE_NP for a recursive mutex, or PTHREAD_MUTEX_ERRORCHECK_NP
 *	for an error-checking mutex. Pass a pointer to this attribute object to
 *	pthread_mutex_init to create a mutex of this kind, and then destroy the attribute
 *	object with pthread_mutexattr_destroy.
 *	This code sequence illustrates creation of an error-checking mutex, for instance:
 */
pthread_mutexattr_t attr;
pthread_mutex_t mutex;
pthread_mutexattr_init (&attr);
pthread_mutexattr_setkind_np (&attr, PTHREAD_MUTEX_ERRORCHECK_NP);
pthread_mutex_init (&mutex, &attr);
pthread_mutexattr_destroy (&attr);


