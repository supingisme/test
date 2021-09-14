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
 *	int execv (const char *filename, char *const argv[]) [Function]
 *	The execv function executes the fle named by flename as a new process image.
 *	The argv argument is an array of null-terminated strings that is used to provide a
 *	value for the argv argument to the main function of the program to be executed. The
 *	last element of this array must be a null pointer. By convention, the frst element
 *	of this array is the fle name of the program sans directory names. See Section 25.1
 *	[Program Arguments], page 646, for full details on how programs can access these
 *	arguments.
 *	The environment for the new process image is taken from the environ variable of
 *	the current process image; see Section 25.4 [Environment Variables], page 678, for
 *	information about environments.
 *	int execl (const char *filename, const char *arg0, . . .) [Function]
 *	This is similar to execv, but the argv strings are specifed individually instead of as
 *	an array. A null pointer must be passed as the last such argument.
 *	int execve (const char *filename, char *const argv[], char *const [Function]
 *	env[])
 *	This is similar to execv, but permits you to specify the environment for the new
 *	program explicitly as the env argument. This should be an array of strings in the
 *	same format as for the environ variable; see Section 25.4.1 [Environment Access],
 *	page 679.
 *	int execle (const char *filename, const char *arg0, char *const env[], [Function]
 *	. . .)
 *	This is similar to execl, but permits you to specify the environment for the new
 *	program explicitly. The environment argument is passed following the null pointer
 *	that marks the last argv argument, and should be an array of strings in the same
 *	format as for the environ variable.
 *	int execvp (const char *filename, char *const argv[]) [Function]
 *	The execvp function is similar to execv, except that it searches the directories listed in
 *	the PATH environment variable (see Section 25.4.2 [Standard Environment Variables],
 *
 *	page 681) to fnd the full fle name of a fle from flename if flename does not contain
 *	a slash.
 *	This function is useful for executing system utility programs, because it looks for
 *	them in the places that the user has chosen. Shells use it to run the commands that
 *	users type.
 *	int execlp (const char *filename, const char *arg0, . . .) [Function]
 *	This function is like execl, except that it performs the same fle name searching as
 *	the execvp function
 */
#include <unistd.h>
//int execv (const char *filename, char *const argv[]);
//int execl (const char *filename, const char *arg0, . . .);
//int execve (const char *filename, char *const argv[], char *const env[]);
//int execle (const char *filename, const char *arg0, char *const env[], ...);
//int execvp (const char *filename, char *const argv[]);
//int execlp (const char *filename, const char *arg0, . . .);

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("argc = %d, argv[0]= %s\n", argc, argv[0]);
	char *args[] = {
		"rongtao", 
		"hello ",
		"world"
	};
	sleep(1);
	execvp("./a.out", args);
}
