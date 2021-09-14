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

/*	int comparison_fn_t(const void *, const void *);
 *
 *	void lfind(const void *key, void *base, size_t *nmemb, size_t size, 
 *				comparision_fn_t compar);
 *		nmemb: 
 *
 *
 *
 * void * lfind (const void *key, void *base, size t *nmemb, size t size, [Function]
 * comparison fn t compar)
 * The lfind function searches in the array with *nmemb elements of size bytes pointed
 * to by base for an element which matches the one pointed to by key. The function
 * pointed to by compar is used decide whether two elements match.
 * The return value is a pointer to the matching element in the array starting at base if
 * it is found. If no matching element is available NULL is returned.
 * The mean runtime of this function is *nmemb/2. This function should only be used if
 * elements often get added to or deleted from the array in which case it might not be
 * useful to sort the array before searching.
 */


 
/* 互动百科 */
int compare(int *x, int *y)
{
    return (*x-*y);
}
int demo()
{
    int array[5] = {35, 12, 54 ,78, 99};
    size_t nelem = 5;
    int key = 12;
    
    int result = lfind(&key, array, &nelem, sizeof(int), compare);
    
    if(result)
        printf("Number %d found, result=%d\n", key, result);
    else
        printf("Number %d not found, result=%d\n", key, result);
}
 
int cmp_str(const char *x, const char *y)
{
    //printf("x:%c, y:%c\n", *x, *y);
	return *x-*y;
}

int main()
{
    demo();
    
    
	// char array[200] = {"Hello World! My name is RongTao."};
	// char key = 'Z';
	// int size = sizeof(char);
	// int nelem = strlen(array);

	// char ret = lfind(&key, array, &nelem, size, cmp_str);

	// printf("nelem:%d, key: %c, ret: %c\n", nelem, key, ret);

	return 0;
}
