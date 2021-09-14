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
#include <stdio.h>

int main()
{
	/*	FILE * freopen (const char *filename, const char *opentype, FILE [Function]
	 *	*stream)
	 *	This function is like a combination of fclose and fopen. It frst closes the stream
	 *	referred to by stream, ignoring any errors that are detected in the process. (Because
	 *	errors are ignored, you should not use freopen on an output stream if you have
	 *	actually done any output using the stream.) Then the fle named by flename is
	 *	opened with mode opentype as for fopen, and associated with the same stream object
	 *	stream.
	 *	If the operation fails, a null pointer is returned; otherwise, freopen returns stream.
	 *	freopen has traditionally been used to connect a standard stream such as stdin with
	 *	a fle of your own choice. This is useful in programs in which use of a standard stream
	 *	for certain purposes is hard-coded. In the GNU C library, you can simply close the
	 *	standard streams and open new ones with fopen. But other systems lack this ability,
	 *	so using freopen is more portable.
	 *	When the sources are compiling with _FILE_OFFSET_BITS == 64 on a 32 bit machine
	 *	this function is in fact freopen64 since the LFS interface replaces transparently the
	 *	old interface.
	 *
	 *	FILE * freopen64 (const char *filename, const char *opentype, FILE [Function]
	 *	*stream)
	 *	This function is similar to freopen. The only diﬀerence is that on 32 bit machine the
	 *	stream returned is able to read beyond the 231 bytes limits imposed by the normal
	 *	interface. It should be noted that the stream pointed to by stream need not be opened
	 *	using fopen64 or freopen64 since its mode is not important for this function.
	 *	If the sources are compiled with _FILE_OFFSET_BITS == 64 on a 32 bits machine this
	 *	function is available under the name freopen and so transparently replaces the old
	 *	interface.
	 */

	FILE *fp1 = freopen("RongTao.txt", "r", stdin);

	//fprintf(fp1, "Hello World\n");
	char str[100];
	fgets(str, 100, fp1);
	printf("hello world RongTao:%s\n", str);

	fclose(fp1);

	return 0;
}
