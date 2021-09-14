/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 26日 星期三 08:58:16 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 21日 星期五 08:57:16 CST. */

#include <stdio.h>
/* The ENVIRON variable contains the environment. */
extern char** environ;
int main ()
{
	char** var;
	for (var = environ; *var != NULL; ++var)
		printf ("%s\n", *var);
	return 0;
}
