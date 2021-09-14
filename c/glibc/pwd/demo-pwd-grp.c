/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:21 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:28 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:59 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/*
 *	29.15 User and Group Database Example
 *	Here is an example program showing the use of the system database inquiry functions. The
 *	program prints some information about the user running the program.
 */

#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main (void)
{
	uid_t me;
	struct passwd *my_passwd;
	struct group *my_group;
	char **members;
	/* Get information about the user ID. */
	me = getuid ();
	my_passwd = getpwuid (me);
	if (!my_passwd)
	{
		printf ("Couldn’t find out about user %d.\n", (int) me);
		exit (EXIT_FAILURE);
	}
	/* Print the information. */
	printf ("I am %s.\n", my_passwd->pw_gecos);
	printf ("My login name is %s.\n", my_passwd->pw_name);
	printf ("My uid is %d.\n", (int) (my_passwd->pw_uid));
	printf ("My home directory is %s.\n", my_passwd->pw_dir);
	printf ("My default shell is %s.\n", my_passwd->pw_shell);
    
	/* Get information about the default group ID. */
	my_group = getgrgid (my_passwd->pw_gid);
	if (!my_group)
	{
		printf ("Couldn’t find out about group %d.\n",
				(int) my_passwd->pw_gid);
		exit (EXIT_FAILURE);
	}
	/* Print the information. */
	printf ("My default group is %s (%d).\n",
			my_group->gr_name, (int) (my_passwd->pw_gid));
	printf ("The members of this group are:\n");
    
	members = my_group->gr_mem;
	while (*members)
	{
		printf (" %s\n", *(members));
		members++;
	}
	return EXIT_SUCCESS;
}
