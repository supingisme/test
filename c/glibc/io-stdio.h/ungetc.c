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

void
skip_whitespace (FILE *stream)
{
	int c;
	do
	{	/* No need to check for EOF because it is not
		 * isspace, and ungetc ignores EOF. */
		c = getc (stream);
		printf("%c\n", c);
	}while (!isspace (c));
	
	ungetc (c==' '?'S':'n', stream);

	c = 'Z';

	c = getc(stream);
	printf("c:%c\n", c);
}

int main()
{
	char s[10] = {"abcdefghij"};

	char ch;

	/*while(ch = ungetc('a', stdout) != 'q' )
	{
		printf("ch = %c\n", ch);
	}*/

	/*FILE *fp = fopen("rong.out", "r");

	ungetc('Q', fp);

	fprintf(fp, "rongadsfadsf\n");

	fclose(fp);*/

	skip_whitespace(stdin);

	return 0;
}
