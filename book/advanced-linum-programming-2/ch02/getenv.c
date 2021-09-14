/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 26日 星期三 08:58:16 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 21日 星期五 08:57:16 CST. */
#include <stdio.h>
#include <stdlib.h>
int main ()
{
	char* server_name = getenv ("HOME");
	if (server_name == NULL)
		/* The SERVER_NAME environment variable was not set. Use the
		 * default. */
		server_name = "server.my-company.com";
	printf ("accessing server %s\n", server_name);
	/* Access the server here... */
	return 0;
}
