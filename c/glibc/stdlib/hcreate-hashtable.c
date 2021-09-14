/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

/*int hcreate (size t nel) [Function]
 * The hcreate function creates a hashing table which can contain at least nel elements.
 * There is no possibility to grow this table so it is necessary to choose the value for
 * nel wisely. The method used to implement this function might make it necessary to
 * make the number of elements in the hashing table larger than the expected maximal
 * number of elements. Hashing tables usually work inefciently if they are flled 80%
 * or more. The constant access time guaranteed by hashing can only be achieved if few
 * collisions exist. See Knuth’s “The Art of Computer Programming, Part 3: Searching
 * and Sorting” for more information.
 *
 */

char *data[] = {
	"alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india",
	"kilo",  "lima",  "mike",    "x-ray", "tango", "uniform", "victor", "whisky", "yankee",
	"zullu", "papa", "oscar", "linux", "unix", "sylincom", "RongTao", "woshi", "nishi",
    "zaima", "shangke", "buhao"
};

int main()
{
	ENTRY e, *ep;

	int i;

	hcreate(30);

	for(i=0;i<24;i++)
	{
		e.key = data[i];
		/*data is just an integer, instead of a pointer to something*/
		e.data = (void*)i;
		ep = hsearch(e, ENTER);

		/*there shuld be no failures*/
		if(ep == NULL)
		{
			fprintf(stderr, "entry failed\n");
			exit(EXIT_FAILURE);
		}
	}

	for(i=20;i<26;i++)
	{
		/*print two entries from the table, and show that two are not in the table*/
		e.key = data[i];
		ep = hsearch(e, FIND);
		printf("%9.9s -> %9.9s:%d\n", e.key, ep?ep->key:NULL, ep?(int)(ep->data):0);
	}
	hdestroy();
	exit(EXIT_SUCCESS);

	return 0;
}
