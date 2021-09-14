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
#include <stdlib.h>
#include <string.h>

/*	size_t fread (void *data, size t size, size t count, FILE *stream) [Function]
 *	This function reads up to count objects of size size into the array data, from the
 *	stream stream. It returns the number of objects actually read, which might be less
 *	than count if a read error occurs or the end of the fle is reached. This function
 *	returns a value of zero (and doesn’t read anything) if either size or count is zero.
 *	If fread encounters end of fle in the middle of an object, it returns the number of
 *	complete objects read, and discards the partial object. Therefore, the stream remains
 *	at the actual end of the fle.
 *	size_t fread_unlocked (void *data, size t size, size t count, FILE [Function]
 *	*stream)
 *	The fread_unlocked function is equivalent to the fread function except that it does
 *	not implicitly lock the stream.
 *	This function is a GNU extension.
 *	size_t fwrite (const void *data, size t size, size t count, FILE [Function]
 *	*stream)
 *	This function writes up to count objects of size size from the array data, to the
 *	stream stream. The return value is normally count, if the call succeeds. Any other
 *	value indicates some sort of error, such as running out of space.
 *	size_t fwrite_unlocked (const void *data, size t size, size t count, [Function]
 *	FILE *stream)
 *	The fwrite_unlocked function is equivalent to the fwrite function except that it
 *	does not implicitly lock the stream.
 *	This function is a GNU extension.
 *
 */

int main()
{
	FILE *fp = fopen("rong.bin", "w");

	float f = 9.91;

	fwrite(&f, sizeof(float), 1, fp);

	fclose(fp);

	fp = fopen("rong.bin", "r");

	f = 0.0;

	fread_unlocked(&f, sizeof(float), 1, fp);

	fclose(fp);

	printf("%f\n", f);

	return 0;
}
