/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:10 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:23 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:30 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:08 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*
 *	char * crypt (const char *key, const char *salt) [Function]
 *	The crypt function takes a password, key, as a string, and a salt character array
 *	which is described below, and returns a printable ASCII string which starts with
 *	another salt. It is believed that, given the output of the function, the best way to
 *	fnd a key that will produce that output is to guess values of key until the original
 *	value of key is found.
 *	The salt parameter does two things. Firstly, it selects which algorithm is used, the
 *	MD5-based one or the DES-based one. Secondly, it makes life harder for someone
 *	trying to guess passwords against a fle containing many passwords; without a salt,
 *	an intruder can make a guess, run crypt on it once, and compare the result with all
 *	the passwords. With a salt, the intruder must run crypt once for each diﬀerent salt.
 *	For the MD5-based algorithm, the salt should consist of the string $1$, followed by up
 *	to 8 characters, terminated by either another $ or the end of the string. The result
 *	of crypt will be the salt, followed by a $ if the salt didn’t end with one, followed
 *	by 22 characters from the alphabet ./0-9A-Za-z, up to 34 characters total. Every
 *	character in the key is signifcant.
 *	For the DES-based algorithm, the salt should consist of two characters from the
 *	alphabet ./0-9A-Za-z, and the result of crypt will be those two characters followed
 *	by 11 more from the same alphabet, 13 in total. Only the frst 8 characters in the
 *	key are signifcant.
 *	The MD5-based algorithm has no limit on the useful length of the password used,
 *	and is slightly more secure. It is therefore preferred over the DES-based algorithm.
 *	When the user enters their password for the frst time, the salt should be set to a
 *	new string which is reasonably random. To verify a password against the result of a
 *	previous call to crypt, pass the result of the previous call as the salt.
 */
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <crypt.h>
#include <stdlib.h>

/*	gcc crypt.c -lcrypt
 */
	
int main(void)
{        
	char *password;

    
	/* Turn it into printable characters from ‘seedchars’. */

	/* Read in the user’s password and encrypt it. */
	password = crypt(getpass("Password:"), "12");
    
	/* Print the results. */
	puts(password);
    
	return 0;
}
