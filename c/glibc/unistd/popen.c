/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
#include <stdio.h>
#include <unistd.h>
int main ()
{
	FILE* stream = popen ("sort", "w");
	fprintf (stream, "This is a test.\n");
	fprintf (stream, "Hello, world.\n");
	fprintf (stream, "My dog has fleas.\n");
	fprintf (stream, "This program is great.\n");
	fprintf (stream, "One fish, two fish.\n");
	return pclose (stream);
}

/**
 *	我竟然在不同的书中看见完全一样的代码
 *	
 *	#include <stdio.h>
 *	#include <unistd.h>
 *	
 *	int main ()
 *	{
 *		FILE* stream = popen (“sort”, “w”);
 *		fprintf (stream, “This is a test.\n”);
 *		fprintf (stream, “Hello, world.\n”);
 *		fprintf (stream, “My dog has fleas.\n”);
 *		fprintf (stream, “This program is great.\n”);
 *		fprintf (stream, “One fish, two fish.\n”);
 *		return pclose (stream);
 *	}
 */
