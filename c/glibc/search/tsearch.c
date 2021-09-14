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
#include <search.h>
#include <time.h>

/*void * tsearch (const void *key, void **rootp, comparison fn t [Function]
 * compar)
 * The tsearch function searches in the tree pointed to by *rootp for an element
 * matching key. The function pointed to by compar is used to determine whether two
 * elements match. See Section 9.1 [Defning the Comparison Function], page 192, for a
 * specifcation of the functions which can be used for the compar parameter.
 * If the tree does not contain a matching entry the key value will be added to the tree.
 * tsearch does not make a copy of the object pointed to by key (how could it since the
 * size is unknown). Instead it adds a reference to this object which means the object
 * must be available as long as the tree data structure is used.
 * The tree is represented by a pointer to a pointer since it is sometimes necessary to
 * change the root node of the tree. So it must not be assumed that the variable pointed
 * to by rootp has the same value after the call. This also shows that it is not safe to
 * call the tsearch function more than once at the same time using the same tree. It is
 * no problem to run it more than once at a time on diﬀerent trees.
 * The return value is a pointer to the matching element in the tree. If a new element
 * was created the pointer points to the new data (which is in fact key). If an entry had
 * to be created and the program ran out of space NULL is returned.
 * void * tfind (const void *key, void *const *rootp, comparison fn t [Function]
 * compar)
 * The tfind function is similar to the tsearch function. It locates an element matching
 * the one pointed to by key and returns a pointer to this element. But if no matching
 * element is available no new element is entered (note that the rootp parameter points
 * to a constant pointer). Instead the function returns NULL.
 * Another advantage of the tsearch function in contrast to the hsearch functions is that
 * there is an easy way to remove elements.
 * void * tdelete (const void *key, void **rootp, comparison fn t [Function]
 * compar)
 * To remove a specifc element matching key from the tree tdelete can be used. It
 * locates the matching element using the same method as tfind. The corresponding
 * element is then removed and a pointer to the parent of the deleted node is returned
 * by the function. If there is no matching entry in the tree nothing can be deleted and
 * the function returns NULL. If the root of the tree is deleted tdelete returns some
 * unspecifed value not equal to NULL.
 *
 *void tdestroy (void *vroot, free fn t freefct) [Function]
 If the complete search tree has to be removed one can use tdestroy. It frees all
 resources allocated by the tsearch function to generate the tree pointed to by vroot.
 For the data in each tree node the function freefct is called. The pointer to the data
 is passed as the argument to the function. If no such work is necessary freefct must
 point to a function doing nothing. It is called in any case.
 This function is a GNU extension and not covered by the System V or X/Open
 *  specifcations.
 *
 *  void tdestroy (void *vroot, free fn t freefct) [Function]
 *  If the complete search tree has to be removed one can use tdestroy. It frees all
 *  resources allocated by the tsearch function to generate the tree pointed to by vroot.
 *  For the data in each tree node the function freefct is called. The pointer to the data
 *  is passed as the argument to the function. If no such work is necessary freefct must
 *  point to a function doing nothing. It is called in any case.
 *  This function is a GNU extension and not covered by the System V or X/Open
 *  specifcations.
 */

struct stu{
	int stu_no;
	char *name;
};

typedef struct stu stu_t;

void *root = NULL;

void *xmalloc(unsigned n)
{
	void *p;
	p = malloc(n);
	if(p) return p;
	fprintf(stderr, "malloc failure\n");
	exit(1);
}

int compare(const void *pa, const void **pb)
{
	return (((stu_t *)pa)->stu_no - ((stu_t *)pb)->stu_no);
}

void action(const void *nodep, const VISIT which, const int depth)
{
	switch(which)
	{
		case preorder:
			break;
		case postorder:
			printf("postorder No. = %6d, Name = %s\n", 
					(*(stu_t **)nodep)->stu_no,
					(*(stu_t **)nodep)->name);
			break;
		case endorder:
			//printf();
			break;
		case leaf:
			printf("leaf      No. = %6d, Name = %s\n", 
					(*(stu_t **)nodep)->stu_no,
					(*(stu_t **)nodep)->name);
			break;
		default:
			break;
	}
}

int main()
{
	stu_t *ptr;
	srand(time(NULL));
	int i;
	for(i=0;i<12;i++)
	{
		ptr = (stu_t *)xmalloc(sizeof(stu_t));
		ptr->stu_no = rand()&0xFF;
		ptr->name = (char *)xmalloc(20);
		sprintf(ptr->name, "sylincom_%d", ptr->stu_no);

		stu_t **rtp = (stu_t**)tsearch(ptr, &root, compare);
        
		if(rtp == NULL)
		{
			printf("NULL\n");
			exit(1);
		}
		else 
		{
			printf("tsearch: No. = %6d, name = %s\n", (*rtp)->stu_no, (*rtp)->name);
		}
	}
    
    ptr = (stu_t *)xmalloc(sizeof(stu_t));
    ptr->stu_no = 88;
    ptr->name = (char*)xmalloc(20);
    sprintf(ptr->name, "sylincom_%d", ptr->stu_no);
    
    tsearch(ptr, &root, compare);
    
    stu_t* rt_find = tfind(ptr, &root, compare);
    if(rt_find == NULL)
    {
        printf("NULL\n");
        exit(1);
    }
    else 
    {
        printf("tfind: No. = %6d, name = %s\n", (rt_find)->stu_no, (rt_find)->name);
    }
    
    puts("second twalk, there is no '88'\n");
    twalk(root, action);


	return 0;
}
