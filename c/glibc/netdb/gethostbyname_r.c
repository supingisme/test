/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:17 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:26 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:43:21 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:11 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */
/**
 *	gethostbyname_r 
 *
 *		P270
 *
 *	int gethostbyname_r (const char *restrict name, struct hostent *restrict [Function]
 *	result_buf, char *restrict buf, size t buflen, struct hostent **restrict
 *	result, int *restrict h_errnop)
 *	The gethostbyname_r function returns information about the host named name.
 *	The caller must pass a pointer to an object of type struct hostent in the result buf
 *	parameter. In addition the function may need extra buﬀer space and the caller must
 *	pass an pointer and the size of the buﬀer in the buf and buﬂen parameters.
 *	A pointer to the buﬀer, in which the result is stored, is available in *result after
 *	the function call successfully returned. If an error occurs or if no entry is found, the
 *	pointer *result is a null pointer. Success is signalled by a zero return value. If the
 *	function failed the return value is an error number. In addition to the errors defned
 *	for gethostbyname it can also be ERANGE. In this case the call should be repeated
 *	with a larger buﬀer. Additional error information is not stored in the global variable
 *	h_errno but instead in the object pointed to by h errnop.
 *	Here’s a small example:
 *
 *
 */	
#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <malloc.h>
#include <string.h>

//struct hostent *gethostbyname_r(const char *hostname,
//								struct hostent *result,
//								char *buf,
//								int buflen,
//								int *h_errnop);

struct hostent *
gethostname (char *host)
{
	struct hostent hostbuf, *hp;
	size_t hstbuflen;
	char *tmphstbuf;
	int res;
	int herr;
	hstbuflen = 1024;
	/* Allocate buffer, remember to free it to avoid memory leakage. */
	tmphstbuf = malloc (hstbuflen);
	while ((res = gethostbyname_r (host, &hostbuf, tmphstbuf, hstbuflen,
					&hp, &herr)) == ERANGE)
	{
		/* Enlarge the buffer. */
		hstbuflen *= 2;
		tmphstbuf = realloc (tmphstbuf, hstbuflen);
	}
	/* Check for errors. */
	if (res || hp == NULL)
		return NULL;
	return hp;
}

int main()
{

		
	return 0;
}
