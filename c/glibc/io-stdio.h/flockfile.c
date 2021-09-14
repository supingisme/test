/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:13 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:24 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:55 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:32 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:09 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:48 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
/*	void flockfile (FILE *stream) [Function]
 *	The flockfile function acquires the internal locking object associated with
 *	the stream stream. This ensures that no other thread can explicitly through
 *	flockfile/ftrylockfile or implicit through a call of a stream function lock
 *	the stream. The thread will block until the lock is acquired. An explicit call to
 *	funlockfile has to be used to release the lock.
 *	int ftrylockfile (FILE *stream) [Function]
 *	The ftrylockfile function tries to acquire the internal locking object associated
 *	with the stream stream just like flockfile. But unlike flockfile this function
 *	does not block if the lock is not available. ftrylockfile returns zero if the lock was
 *	successfully acquired. Otherwise the stream is locked by another thread.
 *
 *	void funlockfile (FILE *stream) [Function]
 *	The funlockfile function releases the internal locking object of the stream stream.
 *	The stream must have been locked before by a call to flockfile or a successful call
 *	of ftrylockfile. The implicit locking performed by the stream operations do not
 *	count. The funlockfile function does not return an error status and the behavior
 *	of a call for a stream which is not locked by the current thread is undefned.
 */
#include <stdio.h>
#include <stdlib.h>

void foo (FILE *fp)
{
	ftrylockfile (fp);
	fputs ("in foo\n", fp);
	/* This is very wrong!!! */
	funlockfile (fp);
}

void foo2 (FILE *fp)
{
	if (ftrylockfile (fp) == 0)
	{
		fputs ("in foo\n", fp);
		funlockfile (fp);
	}
}

void foo3 (FILE *fp, char *buf)
{
	flockfile (fp);
	while (*buf != '\0')
		putc_unlocked (*buf++, fp);
	funlockfile (fp);
}

int main()
{
	FILE *fp;
	{
		fp = fopen("rong.out", "w");
		flockfile (fp);
		fputs ("This is test number ", fp);
		fprintf (fp, "%d\n", 99);
		funlockfile (fp);

		foo(fp);	
		foo2(fp);
		foo3(fp, "Quitrong /");
	}

	return 0;
}
