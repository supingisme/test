/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:56 CST. */
/*

int getpagesize (void) [Function]
The getpagesize function returns the page size of the process. This value is fxed
for the runtime of the process but can vary in diﬀerent runs of the application.
The function is declared in ‘unistd.h’.

long int sysconf (int parameter) [Function]
This function is used to inquire about runtime system parameters. The parameter
argument should be one of the ‘_SC_’ symbols listed below.
The normal return value from sysconf is the value you requested. A value of -1 is
returned both if the implementation does not impose a limit, and in case of an error.
The following errno error conditions are defned for this function:
EINVAL The value of the parameter is invalid.


31.4.2 Constants for sysconf Parameters
Here are the symbolic constants for use as the parameter argument to sysconf. The values
are all integer constants (more specifcally, enumeration type values).
_SC_ARG_MAX
Inquire about the parameter corresponding to ARG_MAX.
_SC_CHILD_MAX
Inquire about the parameter corresponding to CHILD_MAX.
_SC_OPEN_MAX
Inquire about the parameter corresponding to OPEN_MAX.
_SC_STREAM_MAX
Inquire about the parameter corresponding to STREAM_MAX.
_SC_TZNAME_MAX
Inquire about the parameter corresponding to TZNAME_MAX.
_SC_NGROUPS_MAX
Inquire about the parameter corresponding to NGROUPS_MAX.
_SC_JOB_CONTROL
Inquire about the parameter corresponding to _POSIX_JOB_CONTROL.

_SC_SAVED_IDS
Inquire about the parameter corresponding to _POSIX_SAVED_IDS.
_SC_VERSION
Inquire about the parameter corresponding to _POSIX_VERSION.
_SC_CLK_TCK
Inquire about the parameter corresponding to CLOCKS_PER_SEC; see
Section 21.3.1 [CPU Time Inquiry], page 542.
_SC_CHARCLASS_NAME_MAX
Inquire about the parameter corresponding to maximal length allowed for a
character class name in an extended locale specifcation. These extensions are
not yet standardized and so this option is not standardized as well.
_SC_REALTIME_SIGNALS
Inquire about the parameter corresponding to _POSIX_REALTIME_SIGNALS.
_SC_PRIORITY_SCHEDULING
Inquire about the parameter corresponding to _POSIX_PRIORITY_SCHEDULING.
_SC_TIMERS
Inquire about the parameter corresponding to _POSIX_TIMERS.
_SC_ASYNCHRONOUS_IO
Inquire about the parameter corresponding to _POSIX_ASYNCHRONOUS_IO.
_SC_PRIORITIZED_IO
Inquire about the parameter corresponding to _POSIX_PRIORITIZED_IO.
_SC_SYNCHRONIZED_IO
Inquire about the parameter corresponding to _POSIX_SYNCHRONIZED_IO.
_SC_FSYNC
Inquire about the parameter corresponding to _POSIX_FSYNC.
_SC_MAPPED_FILES
Inquire about the parameter corresponding to _POSIX_MAPPED_FILES.
_SC_MEMLOCK
Inquire about the parameter corresponding to _POSIX_MEMLOCK.
_SC_MEMLOCK_RANGE
Inquire about the parameter corresponding to _POSIX_MEMLOCK_RANGE.
_SC_MEMORY_PROTECTION
Inquire about the parameter corresponding to _POSIX_MEMORY_PROTECTION.
_SC_MESSAGE_PASSING
Inquire about the parameter corresponding to _POSIX_MESSAGE_PASSING.
_SC_SEMAPHORES
Inquire about the parameter corresponding to _POSIX_SEMAPHORES.
_SC_SHARED_MEMORY_OBJECTS
Inquire about the parameter corresponding to
_POSIX_SHARED_MEMORY_OBJECTS.
_SC_AIO_LISTIO_MAX
Inquire about the parameter corresponding to _POSIX_AIO_LISTIO_MAX.
_SC_AIO_MAX
Inquire about the parameter corresponding to _POSIX_AIO_MAX.
_SC_AIO_PRIO_DELTA_MAX
Inquire the value by which a process can decrease its asynchronous I/O pri
ority level from its own scheduling priority. This corresponds to the run-time
invariant value AIO_PRIO_DELTA_MAX.
_SC_DELAYTIMER_MAX
Inquire about the parameter corresponding to _POSIX_DELAYTIMER_MAX.
_SC_MQ_OPEN_MAX
Inquire about the parameter corresponding to _POSIX_MQ_OPEN_MAX.
_SC_MQ_PRIO_MAX
Inquire about the parameter corresponding to _POSIX_MQ_PRIO_MAX.
_SC_RTSIG_MAX
Inquire about the parameter corresponding to _POSIX_RTSIG_MAX.
_SC_SEM_NSEMS_MAX
Inquire about the parameter corresponding to _POSIX_SEM_NSEMS_MAX.
_SC_SEM_VALUE_MAX
Inquire about the parameter corresponding to _POSIX_SEM_VALUE_MAX.
_SC_SIGQUEUE_MAX
Inquire about the parameter corresponding to _POSIX_SIGQUEUE_MAX.
_SC_TIMER_MAX
Inquire about the parameter corresponding to _POSIX_TIMER_MAX.
_SC_PII Inquire about the parameter corresponding to _POSIX_PII.
_SC_PII_XTI
Inquire about the parameter corresponding to _POSIX_PII_XTI.
_SC_PII_SOCKET
Inquire about the parameter corresponding to _POSIX_PII_SOCKET.
_SC_PII_INTERNET
Inquire about the parameter corresponding to _POSIX_PII_INTERNET.
_SC_PII_OSI
Inquire about the parameter corresponding to _POSIX_PII_OSI.
_SC_SELECT
Inquire about the parameter corresponding to _POSIX_SELECT.
_SC_UIO_MAXIOV
Inquire about the parameter corresponding to _POSIX_UIO_MAXIOV.
_SC_PII_INTERNET_STREAM
Inquire about the parameter corresponding to _POSIX_PII_INTERNET_STREAM.
_SC_PII_INTERNET_DGRAM
Inquire about the parameter corresponding to _POSIX_PII_INTERNET_DGRAM.
_SC_PII_OSI_COTS
Inquire about the parameter corresponding to _POSIX_PII_OSI_COTS.
_SC_PII_OSI_CLTS
Inquire about the parameter corresponding to _POSIX_PII_OSI_CLTS.
_SC_PII_OSI_M
Inquire about the parameter corresponding to _POSIX_PII_OSI_M.
_SC_T_IOV_MAX
Inquire the value of the value associated with the T_IOV_MAX variable.
_SC_THREADS
Inquire about the parameter corresponding to _POSIX_THREADS.
_SC_THREAD_SAFE_FUNCTIONS
Inquire about the parameter corresponding to
_POSIX_THREAD_SAFE_FUNCTIONS.
_SC_GETGR_R_SIZE_MAX
Inquire about the parameter corresponding to _POSIX_GETGR_R_SIZE_MAX.
_SC_GETPW_R_SIZE_MAX
Inquire about the parameter corresponding to _POSIX_GETPW_R_SIZE_MAX.
_SC_LOGIN_NAME_MAX
Inquire about the parameter corresponding to _POSIX_LOGIN_NAME_MAX.
_SC_TTY_NAME_MAX
Inquire about the parameter corresponding to _POSIX_TTY_NAME_MAX.
_SC_THREAD_DESTRUCTOR_ITERATIONS
Inquire about the parameter corresponding to _POSIX_THREAD_DESTRUCTOR_
ITERATIONS.
_SC_THREAD_KEYS_MAX
Inquire about the parameter corresponding to _POSIX_THREAD_KEYS_MAX.
_SC_THREAD_STACK_MIN
Inquire about the parameter corresponding to _POSIX_THREAD_STACK_MIN.
_SC_THREAD_THREADS_MAX
Inquire about the parameter corresponding to _POSIX_THREAD_THREADS_MAX.
_SC_THREAD_ATTR_STACKADDR
Inquire about the parameter corresponding to
a _POSIX_THREAD_ATTR_STACKADDR.
_SC_THREAD_ATTR_STACKSIZE
Inquire about the parameter corresponding to
_POSIX_THREAD_ATTR_STACKSIZE.
_SC_THREAD_PRIORITY_SCHEDULING
Inquire about the parameter corresponding to _POSIX_THREAD_PRIORITY_
SCHEDULING.
_SC_THREAD_PRIO_INHERIT
Inquire about the parameter corresponding to _POSIX_THREAD_PRIO_INHERIT.
_SC_THREAD_PRIO_PROTECT
Inquire about the parameter corresponding to _POSIX_THREAD_PRIO_PROTECT.
_SC_THREAD_PROCESS_SHARED
Inquire about the parameter corresponding to _POSIX_THREAD_PROCESS_
SHARED.
_SC_2_C_DEV
Inquire about whether the system has the POSIX.2 C compiler command, c89.
_SC_2_FORT_DEV
Inquire about whether the system has the POSIX.2 Fortran compiler command,
		fort77.
		_SC_2_FORT_RUN
		Inquire about whether the system has the POSIX.2 asa command to interpret
		Fortran carriage control.
		_SC_2_LOCALEDEF
		Inquire about whether the system has the POSIX.2 localedef command.
		_SC_2_SW_DEV
		Inquire about whether the system has the POSIX.2 commands ar, make, and
		strip.
		_SC_BC_BASE_MAX
		Inquire about the maximum value of obase in the bc utility.
		_SC_BC_DIM_MAX
		Inquire about the maximum size of an array in the bc utility.
		_SC_BC_SCALE_MAX
		Inquire about the maximum value of scale in the bc utility.
		_SC_BC_STRING_MAX
		Inquire about the maximum size of a string constant in the bc utility.
		_SC_COLL_WEIGHTS_MAX
		Inquire about the maximum number of weights that can necessarily be used in
		defning the collating sequence for a locale.
		_SC_EXPR_NEST_MAX
		Inquire about the maximum number of expressions nested within parentheses
		when using the expr utility.
		_SC_LINE_MAX
		Inquire about the maximum size of a text line that the POSIX.2 text utilities
		can handle.
		_SC_EQUIV_CLASS_MAX
		Inquire about the maximum number of weights that can be assigned to an entry
		of the LC_COLLATE category ‘order’ keyword in a locale defnition. The GNU
		C library does not presently support locale defnitions.
_SC_VERSION
Inquire about the version number of POSIX.1 that the library and kernel sup
port.
_SC_2_VERSION
Inquire about the version number of POSIX.2 that the system utilities support.
_SC_PAGESIZE
Inquire about the virtual memory page size of the machine. getpagesize
returns the same value (see Section 22.4.2 [How to get information about the
		memory subsystem?], page 590).
_SC_NPROCESSORS_CONF
Inquire about the number of confgured processors.
_SC_NPROCESSORS_ONLN
Inquire about the number of processors online.
_SC_PHYS_PAGES
Inquire about the number of physical pages in the system.
_SC_AVPHYS_PAGES
Inquire about the number of available physical pages in the system.
_SC_ATEXIT_MAX
Inquire about the number of functions which can be registered as termination
functions for atexit; see Section 25.6.3 [Cleanups on Exit], page 686.
_SC_XOPEN_VERSION
Inquire about the parameter corresponding to _XOPEN_VERSION.
_SC_XOPEN_XCU_VERSION
Inquire about the parameter corresponding to _XOPEN_XCU_VERSION.
_SC_XOPEN_UNIX
Inquire about the parameter corresponding to _XOPEN_UNIX.
_SC_XOPEN_REALTIME
Inquire about the parameter corresponding to _XOPEN_REALTIME.
_SC_XOPEN_REALTIME_THREADS
Inquire about the parameter corresponding to _XOPEN_REALTIME_THREADS.
_SC_XOPEN_LEGACY
Inquire about the parameter corresponding to _XOPEN_LEGACY.
_SC_XOPEN_CRYPT
Inquire about the parameter corresponding to _XOPEN_CRYPT.
_SC_XOPEN_ENH_I18N
Inquire about the parameter corresponding to _XOPEN_ENH_I18N.
_SC_XOPEN_SHM
Inquire about the parameter corresponding to _XOPEN_SHM.
_SC_XOPEN_XPG2
Inquire about the parameter corresponding to _XOPEN_XPG2.
_SC_XOPEN_XPG3
Inquire about the parameter corresponding to _XOPEN_XPG3.
_SC_XOPEN_XPG4
Inquire about the parameter corresponding to _XOPEN_XPG4.
_SC_CHAR_BIT
Inquire about the number of bits in a variable of type char.
_SC_CHAR_MAX
Inquire about the maximum value which can be stored in a variable of type
char.
_SC_CHAR_MIN
Inquire about the minimum value which can be stored in a variable of type
char.
_SC_INT_MAX
Inquire about the maximum value which can be stored in a variable of type
int.
_SC_INT_MIN
Inquire about the minimum value which can be stored in a variable of type int.
_SC_LONG_BIT
Inquire about the number of bits in a variable of type long int.
_SC_WORD_BIT
Inquire about the number of bits in a variable of a register word.
_SC_MB_LEN_MAX
Inquire the maximum length of a multi-byte representation of a wide character
value.
_SC_NZERO
Inquire about the value used to internally represent the zero priority level for
the process execution.
SC_SSIZE_MAX
Inquire about the maximum value which can be stored in a variable of type
ssize_t.
_SC_SCHAR_MAX
Inquire about the maximum value which can be stored in a variable of type
signed char.
_SC_SCHAR_MIN
Inquire about the minimum value which can be stored in a variable of type
signed char.
_SC_SHRT_MAX
Inquire about the maximum value which can be stored in a variable of type
short int.
_SC_SHRT_MIN
Inquire about the minimum value which can be stored in a variable of type
short int.
_SC_UCHAR_MAX
Inquire about the maximum value which can be stored in a variable of type
unsigned char.
_SC_UINT_MAX
Inquire about the maximum value which can be stored in a variable of type
unsigned int.
_SC_ULONG_MAX
Inquire about the maximum value which can be stored in a variable of type
unsigned long int.
_SC_USHRT_MAX
Inquire about the maximum value which can be stored in a variable of type
unsigned short int.
_SC_NL_ARGMAX
Inquire about the parameter corresponding to NL_ARGMAX.
_SC_NL_LANGMAX
Inquire about the parameter corresponding to NL_LANGMAX.
_SC_NL_MSGMAX
Inquire about the parameter corresponding to NL_MSGMAX.
_SC_NL_NMAX
Inquire about the parameter corresponding to NL_NMAX.
_SC_NL_SETMAX
Inquire about the parameter corresponding to NL_SETMAX.
_SC_NL_TEXTMAX
Inquire about the parameter corresponding to NL_TEXTMAX.

*/
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

//int getpagesize (void)


/*
 *	We recommend that you frst test for a macro defnition for the parameter you are interested
 *	in, and call sysconf only if the macro is not defned. For example, here is how to test
 *	whether job control is supported:
 */
int have_job_control (void)
{
#ifdef _POSIX_JOB_CONTROL
	return 1;
#else
	int value = sysconf (_SC_JOB_CONTROL);
	if (value < 0)
		/* If the system is that badly wedged,
		 * there’s no use trying to go on. */
		//fatal (strerror (errno));
		strerror(errno);
	return value;
#endif
}

/*
 *	Here is how to get the value of a numeric limit:
 */
int get_child_max ()
{
#ifdef CHILD_MAX
	return CHILD_MAX;
#else
	int value = sysconf (_SC_CHILD_MAX);
	if (value < 0)
		//fatal (strerror (errno));
		strerror(errno);
	return value;
#endif
}

int main()
{
	have_job_control();
	get_child_max();

    int ret = getpagesize();
    printf("ret = %d\n", ret);
    
    
    /*
    Widely available on System V derived systems is a method to get 
    information about the physical memory the system has. The call
    */
    ret = sysconf (_SC_PHYS_PAGES);
    printf("ret = %d\n", ret);
    
    
    ret = sysconf (_SC_AVPHYS_PAGES);
    printf("ret = %d\n", ret);
    
    
    
	return 0;
}
