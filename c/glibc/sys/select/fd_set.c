/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:32 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:16 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:59 CST. */
#include <stdio.h>


/* Maximum number of file descriptors in `cell_set'.  */
#define CELL_SETSIZE    __CELL_SETSIZE

/* The cell_set member is required to be an array of longs.  */
typedef long int __cell_mask;

/* Number of descriptors that can fit in an `cell_set'.  */
#define    __CELL_SETSIZE        256

/* It's easier to assume 8-bit bytes than to get CHAR_BIT.  */
#define __NCELLBITS     (8 * (int) sizeof (__cell_mask))
#define __CELL_ELT(d)   ((d) / __NCELLBITS)
#define __CELL_MASK(d)  ((__cell_mask) (1UL << ((d) % __NCELLBITS)))

/* cell_set for select and pselect.  */
typedef struct {
    __cell_mask __cells_bits[__CELL_SETSIZE / __NCELLBITS];
#define __CELLS_BITS(set) ((set)->__cells_bits)
} cell_set;
  
/* We don't use `memset' because this would require a prototype and
   the array isn't too big.  */
#define __CELL_ZERO(s) \
    do {    \
        unsigned int __i;   \
        cell_set *__arr = (s);  \
        for (__i = 0; __i < sizeof (cell_set) / sizeof (__cell_mask); ++__i)    \
            __CELLS_BITS (__arr)[__i] = 0;  \
    } while (0)
#define __CELL_SET(d, s) \
    ((void) (__CELLS_BITS (s)[__CELL_ELT(d)] |= __CELL_MASK(d)))
#define __CELL_CLR(d, s) \
    ((void) (__CELLS_BITS (s)[__CELL_ELT(d)] &= ~ __CELL_MASK(d)))
#define __CELL_ISSET(d, s) \
    ((__CELLS_BITS (s)[__CELL_ELT (d)] & __CELL_MASK (d)) != 0)

/* Access macros for `cell_set'.  */
#define    CELL_SET(cell, cellsetp)    __CELL_SET (cell, cellsetp)
#define    CELL_CLR(cell, cellsetp)    __CELL_CLR (cell, cellsetp)
#define    CELL_ISSET(cell, cellsetp)    __CELL_ISSET (cell, cellsetp)
#define    CELL_ZERO(cellsetp)        __CELL_ZERO (cellsetp)
  
int main()
{
    cell_set set;
    
    CELL_ZERO(&set);
    
    CELL_SET(2, &set);
    
    printf("%d\n", set.__cells_bits[0]);
   
	CELL_SET(0, &set);
    printf("%d\n", set.__cells_bits[0]);


    CELL_SET(1, &set);
    printf("%d\n", set.__cells_bits[0]);
    CELL_SET(257, &set);
    
    printf("%d\n", set.__cells_bits[0]);
    CELL_CLR(257, &set);
    
    printf("%d\n", set.__cells_bits[0]);
    
    CELL_SET(2, &set);
    printf("isset: %d\n", CELL_ISSET(22, &set));
}
