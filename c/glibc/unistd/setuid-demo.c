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
 *	Here’s an example showing how to set up a program that changes its eﬀective user ID.
 *	This is part of a game program called caber-toss that manipulates a fle ‘scores’
 *	that should be writable only by the game program itself. The program assumes that its
 *	executable fle will be installed with the setuid bit set and owned by the same user as the
 *	‘scores’ fle. Typically, a system administrator will set up an account like games for this
 *	purpose.
 *	The executable fle is given mode 4755, so that doing an ‘ls -l’ on it produces output
 *	like:
 *	-rwsr-xr-x 1 games 184422 Jul 30 15:17 caber-toss
 *	The setuid bit shows up in the fle modes as the ‘s’.
 *	The scores fle is given mode 644, and doing an ‘ls -l’ on it shows:
 *	-rw-r--r-- 1 games 0 Jul 31 15:33 scores
 *	Here are the parts of the program that show how to set up the changed user ID. This
 *	program is conditionalized so that it makes use of the fle IDs feature if it is supported, and
 *	otherwise uses setreuid to swap the eﬀective and real user IDs.
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define SCORES_FILE "scores"


/* Remember the eﬀective and real UIDs. */
static uid_t euid, ruid;
/* Restore the eﬀective UID to its original value. */
void do_setuid (void)
{
	int status;
#ifdef _POSIX_SAVED_IDS
	status = seteuid (euid);
#else
	status = setreuid (ruid, euid);
#endif
	if (status < 0) {
		fprintf (stderr, "Couldn’t set uid.\n");
		exit (status);
	}
}

/* Set the eﬀective UID to the real UID. */
void undo_setuid (void)
{
	int status;
#ifdef _POSIX_SAVED_IDS
	status = seteuid (ruid);
#else
	status = setreuid (euid, ruid);
#endif
	if (status < 0) {
		fprintf (stderr, "Couldn’t set uid.\n");
		exit (status);
	}
}

/* Record the score. */
int
record_score (int score)
{
	FILE *stream;
	char *myname;
	/* Open the scores fle. */
	do_setuid ();
	stream = fopen (SCORES_FILE, "a");
	undo_setuid ();
	/* Write the score to the fle. */
	if (stream)
	{
		myname = cuserid (NULL);
		if (score < 0)
			fprintf (stream, "%10s: Couldn’t lift the caber.\n", myname);
		else
			fprintf (stream, "%10s: %d feet.\n", myname, score);
		fclose (stream);
		return 0;
	}
	else
		return -1;
}


/* Main program. */
int main (void)
{
	/* Remember the real and eﬀective user IDs. */
	ruid = getuid ();
	euid = geteuid ();
	undo_setuid ();
	/* Do the game and record the score. */
	record_score(12);


}
