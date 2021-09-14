/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */


/**
 *	The readlink system call retrieves the target of a symbolic link. It takes three arguments: the path
 *	to the symbolic link, a buffer to receive the target of the link, and the length of that buffer.
 *	Unusually, readlink does not NUL-terminate the target path that it fills into the buffer. It does,
 *	however, return the number of characters in the target path, so NUL-terminating the string is
 *	simple.
 *	If the first argument to readlink points to a file that isn't a symbolic link, readlink sets errno to
 *	EINVAL and returns -1.
 *	The small program in Listing 8.9 prints the target of the symbolic link specified on its command
 *	line.
 */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>

/**
 *	Usage:
 *		% ln -s /usr/bin/wc my_link
 *		% ./print-symlink my_link
 *      /usr/bin/wc
 *
 *  [rongtao@localhost unistd]$ ll my_link 
 *  lrwxrwxrwx 1 rongtao rongtao 11 6月  18 08:16 my_link -> /usr/bin/wc
 *  [rongtao@localhost unistd]$ ./a.out my_link 
 *  /usr/bin/wc
 */

/**
 *	跟linux的ln命令挂钩的使用
 */
int main (int argc, char* argv[])
{
	char target_path[256];
	char* link_path = argv[1];
	/* Attempt to read the target of the symbolic link. */
	int len = readlink (link_path, target_path, sizeof (target_path));
	if (len == -1) 
	{
		/* The call failed. */
		if (errno == EINVAL)
			/* It's not a symbolic link; report that. */
			fprintf (stderr, "%s is not a symbolic link\n", link_path);
		else
			/* Some other problem occurred; print the generic message. */
			perror ("readlink");
		return 1;
	}
	else 
	{
		/* NUL-terminate the target path. */
		target_path[len] = '\0';
		/* Print it. */
		printf ("%s\n", target_path);
		return 0;
	}
}
