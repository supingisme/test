/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:56 CST. */
/*
 *	long int pathconf (const char *filename, int parameter) [Function]
 *	This function is used to inquire about the limits that apply to the fle named flename.
 *	The parameter argument should be one of the ‘_PC_’ constants listed below.
 *	The normal return value from pathconf is the value you requested. A value of -1 is
 *	returned both if the implementation does not impose a limit, and in case of an error.
 *	In the former case, errno is not set, while in the latter case, errno is set to indicate
 *	the cause of the problem. So the only way to use this function robustly is to store 0
 *	into errno just before calling it.
 *	Besides the usual fle name errors (see Section 11.2.3 [File Name Errors], page 224),
 *	the following error condition is defned for this function:
 *	EINVAL The value of parameter is invalid, or the implementation doesn’t support
 *	the parameter for the specifc fle.
 *
 *
 *
 *	_PC_LINK_MAX
 *	Inquire about the value of LINK_MAX.
 *	_PC_MAX_CANON
 *	Inquire about the value of MAX_CANON.
 *	_PC_MAX_INPUT
 *	Inquire about the value of MAX_INPUT.
 *	_PC_NAME_MAX
 *	Inquire about the value of NAME_MAX.
 *	_PC_PATH_MAX
 *	Inquire about the value of PATH_MAX.
 *	_PC_PIPE_BUF
 *	Inquire about the value of PIPE_BUF.
 *	_PC_CHOWN_RESTRICTED
 *	Inquire about the value of _POSIX_CHOWN_RESTRICTED.
 *	_PC_NO_TRUNC
 *	Inquire about the value of _POSIX_NO_TRUNC.
 *	_PC_VDISABLE
 *	Inquire about the value of _POSIX_VDISABLE.
 *	_PC_SYNC_IO
 *	Inquire about the value of _POSIX_SYNC_IO.
 *	_PC_ASYNC_IO
 *	Inquire about the value of _POSIX_ASYNC_IO.
 *	_PC_PRIO_IO
 *	Inquire about the value of _POSIX_PRIO_IO.
 *	_PC_FILESIZEBITS
 *	Inquire about the availability of large fles on the flesystem.
 *	_PC_REC_INCR_XFER_SIZE
 *	Inquire about the value of POSIX_REC_INCR_XFER_SIZE.
 *	_PC_REC_MAX_XFER_SIZE
 *	Inquire about the value of POSIX_REC_MAX_XFER_SIZE.
 *	_PC_REC_MIN_XFER_SIZE
 *	Inquire about the value of POSIX_REC_MIN_XFER_SIZE.
 *	_PC_REC_XFER_ALIGN
 *	Inquire about the value of POSIX_REC_XFER_ALIGN.
 */

#include <stdio.h>
#include <unistd.h>

int main()
{
	pathconf("./", _PC_LINK_MAX);


	return 0;
}
