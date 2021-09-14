/**
 *	#include <sys/timeb.h>
 *
 *	int ftime(struct timeb *tp);
 *
 *	DESCRIPTION
 *	This  function  returns  the  current  time  as  seconds  and  milliseconds  since the Epoch,
 *	1970-01-01 00:00:00 +0000 (UTC).  The time is returned in tp, which is declared as follows:
 *
 *	struct timeb {
 *	time_t         time;
 *	unsigned short millitm;
 *	short          timezone;
 *	short          dstflag;
 *	};
 */	
#include <sys/timeb.h>
#include <stdio.h>

int main()
{
	struct timeb timeb;
	ftime(&timeb);
	printf("%ld, %d,%d,%d\n", timeb.time, timeb.millitm, timeb.timezone, timeb.dstflag);


	return 0;
}
