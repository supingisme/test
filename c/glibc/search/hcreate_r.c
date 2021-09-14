/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:29 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:00 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
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
 *
 *
 *
 * int hcreate_r (size t nel, struct hsearch data *htab) [Function]
 * The hcreate_r function initializes the object pointed to by htab to contain a hashing
 * table with at least nel elements. So this function is equivalent to the hcreate function
 * except that the initialized data structure is controlled by the user.
 * This allows having more than one hashing table at one time. The memory neces
 * sary for the struct hsearch_data object can be allocated dynamically. It must be
 * initialized with zero before calling this function.
 * The return value is non-zero if the operation was successful. If the return value is
 * zero, something went wrong, which probably means the programs ran out of memory.
 * void hdestroy_r (struct hsearch data *htab) [Function]
 * The hdestroy_r function frees all resources allocated by the hcreate_r function for
 * this very same object htab. As for hdestroy it is the programs responsibility to free
 * the strings for the elements of the table.
 * int hsearch_r (ENTRY item, ACTION action, ENTRY **retval, [Function]
 * struct hsearch data *htab)
 * The hsearch_r function is equivalent to hsearch. The meaning of the frst two
 * arguments is identical. But instead of operating on a single global hashing table the
 * function works on the table described by the object pointed to by htab (which is
 * initialized by a call to hcreate_r).
 * Another diﬀerence to hcreate is that the pointer to the found entry in the table is
 * not the return value of the functions. It is returned by storing it in a pointer variables
 * pointed to by the retval parameter. The return value of the function is an integer
 * value indicating success if it is non-zero and failure if it is zero. In the latter case the
 * global variable errno signals the reason for the failure.
 * ENOMEM The table is flled and hsearch_r was called with an so far unknown key
 * and action set to ENTER.
 * ESRCH The action parameter is FIND and no corresponding element is found in
 * the table.
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
