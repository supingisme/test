/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:12 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:31 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:09 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
#include <stdio.h>
#include <iconv.h>
#include <wchar.h>
#include <errno.h>
#include <string.h>

int
file2wcs (int fd, const char *charset, wchar_t *outbuf, size_t avail)
{
    char inbuf[BUFSIZ];
    size_t insize = 0;
    char *wrptr = (char *) outbuf;
    int result = 0;
    iconv_t cd;
    cd = iconv_open ("WCHAR_T", charset);
    if (cd == (iconv_t) -1)
    {
        /* Something went wrong. */
        if (errno == EINVAL)
            error (0, 0, "conversion from '%s' to wchar_t not available",
            charset);
        else
            perror ("iconv_open");
        /* Terminate the output string. */
        *outbuf = L'\0';
        return -1;
    }
    while (avail > 0)
    {
        size_t nread;
        size_t nconv;
        char *inptr = inbuf;
        /* Read more input. */
        nread = read (fd, inbuf + insize, sizeof (inbuf) - insize);
        if (nread == 0)
        {
            /* When we come here the fle is completely read.
            This still could mean there are some unused
            characters in the inbuf. Put them back. */
            if (lseek (fd, -insize, SEEK_CUR) == -1)
                result = -1;
            /* Now write out the byte sequence to get into the
            initial state if this is necessary. */
            iconv (cd, NULL, NULL, &wrptr, &avail);
            break;
        }
        insize += nread;
        /* Do the conversion. */
        nconv = iconv (cd, &inptr, &insize, &wrptr, &avail);
        if (nconv == (size_t) -1)
        {
            /* Not everything went right. It might only be
            an unfnished byte sequence at the end of the
            buﬀer. Or it is a real problem. */
            if (errno == EINVAL)
            /* This is harmless. Simply move the unused
            bytes to the beginning of the buﬀer so that
            they can be used in the next round. */
                memmove (inbuf, inptr, insize);
            else
            {
                /* It is a real problem. Maybe we ran out of
                space in the output buﬀer or we have invalid
                input. In any case back the fle pointer to
                the position of the last processed byte. */
                lseek (fd, -insize, SEEK_CUR);
                result = -1;
                break;
            }
        }
    }
    /* Terminate the output string. */
    if (avail >= sizeof (wchar_t))
        *((wchar_t *) wrptr) = L'\0';
    
    if (iconv_close (cd) != 0)
        perror ("iconv_close");
    
    return (wchar_t *) wrptr - outbuf;
}

int main()
{
    iconv_t iconv_open("utf-8", "gb2312");
    
    return 0;
}