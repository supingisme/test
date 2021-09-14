
#include <unistd.h> /* for libc5 */
#include <sys/io.h> /* for glibc */

//set port input/output permissions
/* If TURN_ON is TRUE, request for permission to do direct i/o on the
   port numbers in the range [FROM,FROM+NUM-1].  Otherwise, turn I/O
   permission off for that range.  This call requires root privileges.

   Portability note: not all Linux platforms support this call.  Most
   platforms based on the PC I/O architecture probably will, however.
   E.g., Linux/Alpha for Alpha PCs supports this.  */
/**
 *	获得对IO端口操作的权限
 */
int ioperm(unsigned long from, unsigned long num, int turn_on);


SYSCALL_DEFINE3(ioperm, unsigned long, from, unsigned long, num, int, turn_on)
{
	return ksys_ioperm(from, num, turn_on);
}

