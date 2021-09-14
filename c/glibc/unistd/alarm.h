#include <unistd.h>

//set an alarm clock for delivery of a signal
unsigned int alarm(unsigned int seconds);



/*
 * For backwards compatibility?  This can be done in libc so Alpha
 * and all newer ports shouldn't need it.
 */
SYSCALL_DEFINE1(alarm, unsigned int, seconds)
{
	return alarm_setitimer(seconds);
}

