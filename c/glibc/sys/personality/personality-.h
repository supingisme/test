#include <sys/personality.h>

//set the process execution domain
int personality(unsigned long persona);



SYSCALL_DEFINE1(personality, unsigned int, personality)
{
	unsigned int old = current->personality;

	if (personality != 0xffffffff)
		set_personality(personality);

	return old;
}

