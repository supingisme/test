/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:14 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:25 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:56 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:10 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:48 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
/* Prototypes for __malloc_hook, __free_hook */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "__malloc_hook.h"

/* Prototypes for our hooks. */
static void  my_init_hook   (void);
static void *new_malloc_hook(size_t);
static void  new_free_hook  (void*);
static void *old_malloc_hook;
static void *old_free_hook;

/* Override initializing hook from the C library. */
void (*__MALLOC_HOOK_VOLATILE __malloc_initialize_hook) (void) = my_init_hook;

static void my_init_hook(void)
{
    old_malloc_hook = __malloc_hook;
    old_free_hook   = __free_hook;
    __malloc_hook   = new_malloc_hook;
    __free_hook     = new_free_hook;
}

static void *new_malloc_hook(size_t size)
{
    void *result;
    /* Restore all old hooks */
    __malloc_hook   = old_malloc_hook;
    __free_hook     = old_free_hook;
    /* Call recursively */
    result = malloc (size);
    memset(result, 0, size);
    /* Save underlying hooks */
    old_malloc_hook = __malloc_hook;
    old_free_hook   = __free_hook;
    /* printf might call malloc, so protect it too. */
    printf ("malloc pointer(%p), size(%d)\n", result, (unsigned int) size);
    /* Restore our own hooks */
    __malloc_hook   = new_malloc_hook;
    __free_hook     = new_free_hook;
    return result;
}
static void new_free_hook(void *ptr)
{
    /* Restore all old hooks */
    __malloc_hook   = old_malloc_hook;
    __free_hook     = old_free_hook;
    /* Call recursively */
    free (ptr);
    /* Save underlying hooks */
    old_malloc_hook = __malloc_hook;
    old_free_hook   = __free_hook;
    /* printf might call free, so protect it too. */
    printf ("free pointer(%p)\n", ptr);
    /* Restore our own hooks */
    __malloc_hook   = new_malloc_hook;
    __free_hook     = new_free_hook;
}


