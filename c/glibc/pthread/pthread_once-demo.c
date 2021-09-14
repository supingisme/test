/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 24日 星期一 08:52:25 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:19 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:28 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 09:02:19 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:59 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:12 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:50 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/* include readline1 */
#include <pthread.h>
#include <stdio.h>
#include <malloc.h>
#include <errno.h>

#define MAXLINE 256

static pthread_key_t    rl_key;
static pthread_once_t    rl_once = PTHREAD_ONCE_INIT;

static void
readline_destructor(void *ptr)
{
    free(ptr);
}

static void
readline_once(void)
{
    pthread_key_create(&rl_key, readline_destructor);
    printf("%s\n", __func__);
}

typedef struct {
  int     rl_cnt;            /* initialize to 0 */
  char    *rl_bufptr;            /* initialize to rl_buf */
  char     rl_buf[MAXLINE];
} Rline;
/* end readline1 */

/* include readline2 */
static ssize_t
my_read(Rline *tsd, int fd, char *ptr)
{
    if (tsd->rl_cnt <= 0) {
again:
        if ( (tsd->rl_cnt = read(fd, tsd->rl_buf, MAXLINE)) < 0) {
            if (errno == EINTR)
                goto again;
            return(-1);
        } else if (tsd->rl_cnt == 0)
            return(0);
        tsd->rl_bufptr = tsd->rl_buf;
    }

    tsd->rl_cnt--;
    *ptr = *tsd->rl_bufptr++;
    return(1);
}

ssize_t
readline(int fd, void *vptr, size_t maxlen)
{
    size_t        n, rc;
    char    c, *ptr;
    Rline    *tsd;

    pthread_once(&rl_once, readline_once);
    if ( (tsd = pthread_getspecific(rl_key)) == NULL) {
        tsd = calloc(1, sizeof(Rline));        /* init to 0 */
        pthread_setspecific(rl_key, tsd);
    }

    ptr = vptr;
    for (n = 1; n < maxlen; n++) {
        if ( (rc = my_read(tsd, fd, &c)) == 1) {
            *ptr++ = c;
            if (c == '\n')
                break;
        } else if (rc == 0) {
            *ptr = 0;
            return(n - 1);        /* EOF, n - 1 bytes read */
        } else
            return(-1);        /* error, errno set by read() */
    }

    *ptr = 0;
    return(n);
}
/* end readline2 */

ssize_t
Readline(int fd, void *ptr, size_t maxlen)
{
    ssize_t        n;

    if ( (n = readline(fd, ptr, maxlen)) < 0)
        printf("readline error\n");
    return(n);
}


int main()
{
    char line[MAXLINE];
    
    Readline(fileno(stdin), line, MAXLINE);
    
    printf("Line: %s\n", line);
    Readline(fileno(stdin), line, MAXLINE);
    
    printf("Line: %s\n", line);
    
    return 0;
}