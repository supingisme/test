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
/*	ssize_t getline (char **lineptr, size t *n, FILE *stream) [Function]
 *	This function reads an entire line from stream, storing the text (including the new
 *	line and a terminating null character) in a buﬀer and storing the buﬀer address in
 *	*lineptr.
 *	Before calling getline, you should place in *lineptr the address of a buﬀer *n
 *	bytes long, allocated with malloc. If this buﬀer is long enough to hold the line,
 *	getline stores the line in this buﬀer. Otherwise, getline makes the buﬀer bigger
 *	using realloc, storing the new buﬀer address back in *lineptr and the increased
 *	size back in *n. See Section 3.2.2 [Unconstrained Allocation], page 33.
 *	If you set *lineptr to a null pointer, and *n to zero, before the call, then getline
 *	allocates the initial buﬀer for you by calling malloc.
 *	In either case, when getline returns, *lineptr is a char * which points to the text
 *	of the line.
 *	When getline is successful, it returns the number of characters read (including
 *	the newline, but not including the terminating null). This value enables you to
 *	distinguish null characters that are part of the line from the null character inserted
 *	as a terminator.
 *	This function is a GNU extension, but it is the recommended way to read lines from
 *	a stream. The alternative standard functions are unreliable.
 *	If an error occurs or end of fle is reached without any bytes read, getline returns
 *	-1.
 *
 *	ssize_t getdelim (char **lineptr, size t *n, int delimiter, FILE [Function]
 *	*stream)
 *	This function is like getline except that the character which tells it to stop reading
 *	is not necessarily newline. The argument delimiter specifes the delimiter character;
 *	getdelim keeps reading until it sees that character (or end of fle).
 *	The text is stored in lineptr, including the delimiter character and a terminating null.
 *	Like getline, getdelim makes lineptr bigger if it isn’t big enough.
 *	getline is in fact implemented in terms of getdelim, just like this:
 *	ssize_t
 *	getline (char **lineptr, size_t *n, FILE *stream)
 *	{
 *	return getdelim (lineptr, n, ’\n’, stream);
 *	}
 *	char * fgets (char *s, int count, FILE *stream) [Function]
 *	The fgets function reads characters from the stream stream up to and including a
 *	newline character and stores them in the string s, adding a null character to mark
 *	the end of the string. You must supply count characters worth of space in s, but the
 *	number of characters read is at most count − 1. The extra character space is used to
 *	hold the null character at the end of the string.
 *	If the system is already at end of fle when you call fgets, then the contents of the
 *	array s are unchanged and a null pointer is returned. A null pointer is also returned
 *	if a read error occurs. Otherwise, the return value is the pointer s.
 *	Warning: If the input data has a null character, you can’t tell. So don’t use fgets
 *	unless you know the data cannot contain a null. Don’t use it to read fles edited by the
 *	user because, if the user inserts a null character, you should either handle it properly
 *	or print a clear error message. We recommend using getline instead of fgets.
 *	wchar_t * fgetws (wchar t *ws, int count, FILE *stream) [Function]
 *	The fgetws function reads wide characters from the stream stream up to and includ
 *	ing a newline character and stores them in the string ws, adding a null wide character
 *	to mark the end of the string. You must supply count wide characters worth of space
 *	in ws, but the number of characters read is at most count − 1. The extra character
 *	space is used to hold the null wide character at the end of the string.
 *	If the system is already at end of fle when you call fgetws, then the contents of the
 *	array ws are unchanged and a null pointer is returned. A null pointer is also returned
 *	if a read error occurs. Otherwise, the return value is the pointer ws.
 *	Warning: If the input data has a null wide character (which are null bytes in the
 *	input stream), you can’t tell. So don’t use fgetws unless you know the data cannot
 *	contain a null. Don’t use it to read fles edited by the user because, if the user inserts
 *	a null character, you should either handle it properly or print a clear error message.
 *	char * fgets_unlocked (char *s, int count, FILE *stream) [Function]
 *	The fgets_unlocked function is equivalent to the fgets function except that it does
 *	not implicitly lock the stream.
 *	This function is a GNU extension.
 *
 *	wchar_t * fgetws_unlocked (wchar t *ws, int count, FILE *stream) [Function]
 *	The fgetws_unlocked function is equivalent to the fgetws function except that it
 *	does not implicitly lock the stream.
 *	This function is a GNU extension.
 *	char * gets (char *s) [Deprecated function]
*	The function gets reads characters from the stream stdin up to the next newline
*	character, and stores them in the string s. The newline character is discarded (note
		*	that this diﬀers from the behavior of fgets, which copies the newline character into
		*	the string). If gets encounters a read error or end-of-fle, it returns a null pointer;
*	otherwise it returns s.
*	Warning: The gets function is very dangerous because it provides no protection
*	against overﬂowing the string s. The GNU library includes it for compatibility only.
*	You should always use fgets or getline instead. To remind you of this, the linker
*	(if using GNU ld) will issue a warning whenever you use gets.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *str = malloc(256);
	int len = 0;
	
	//FILE *fp = fopen(__FILE__, "r");
	
	while(getline(&str, &len, stdin) >= 0)
	{
		if(strncmp(str, "quit", 4) == 0)
		{
			exit(0);
		}
		printf("%d:%s\n", len, str);
	}

	return 0;
}

