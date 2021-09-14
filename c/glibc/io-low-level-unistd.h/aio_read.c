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
/*	异步读写
 *
 *	struct aiocb [Data Type]
 *	The POSIX.1b standard mandates that the struct aiocb structure contains at least
 *	the members described in the following table. There might be more elements which
 *	are used by the implementation, but depending upon these elements is not portable
 *	and is highly deprecated.
 *	int aio_fildes
 *	This element specifes the fle descriptor to be used for the operation. It
 *	must be a legal descriptor, otherwise the operation will fail.
 *	The device on which the fle is opened must allow the seek operation.
 *	I.e., it is not possible to use any of the AIO operations on devices like
 *	terminals where an lseek call would lead to an error.
 *	off_t aio_offset
 *	This element specifes the oﬀset in the fle at which the operation (input
 *	or output) is performed. Since the operations are carried out in arbitrary
 *	order and more than one operation for one fle descriptor can be started,
 *	one cannot expect a current read/write position of the fle descriptor.
 *	volatile void *aio_buf
 *	This is a pointer to the buﬀer with the data to be written or the place
 *	where the read data is stored.
 *	size_t aio_nbytes
 *	This element specifes the length of the buﬀer pointed to by aio_buf.
 *	int aio_reqprio
 *	If the platform has defned _POSIX_PRIORITIZED_IO and _POSIX_
 *	PRIORITY_SCHEDULING, the AIO requests are processed based on the
 *	current scheduling priority. The aio_reqprio element can then be used
 *	to lower the priority of the AIO operation.
 *	struct sigevent aio_sigevent
 *	This element specifes how the calling process is notifed once the opera
 *	tion terminates. If the sigev_notify element is SIGEV_NONE, no notifca
 *	tion is sent. If it is SIGEV_SIGNAL, the signal determined by sigev_signo
 *	is sent. Otherwise, sigev_notify must be SIGEV_THREAD. In this case,
 *	a thread is created which starts executing the function pointed to by
 *	sigev_notify_function.
 *
 *	int aio_lio_opcode
 *	This element is only used by the lio_listio and lio_listio64 func
 *	tions. Since these functions allow an arbitrary number of operations to
 *	start at once, and each operation can be input or output (or nothing),
 *	the information must be stored in the control block. The possible values
 *	are:
 *	LIO_READ Start a read operation. Read from the fle at position aio_
 *	offset and store the next aio_nbytes bytes in the buﬀer
 *	pointed to by aio_buf.
 *	LIO_WRITE
 *	Start a write operation. Write aio_nbytes bytes starting at
 *	aio_buf into the fle starting at position aio_offset.
 *	LIO_NOP Do nothing for this control block. This value is useful some
 *	times when an array of struct aiocb values contains holes,
 *	i.e., some of the values must not be handled although the
 *	whole array is presented to the lio_listio function.
 *
 *
 *	When the sources are compiled using _FILE_OFFSET_BITS == 64 on a 32 bit machine,
 *	this type is in fact struct aiocb64, since the LFS interface transparently replaces
 *	the struct aiocb defnition.
 *	For use with the AIO functions defned in the LFS, there is a similar type defned which
 *	replaces the types of the appropriate members with larger types but otherwise is equivalent
 *	to struct aiocb. Particularly, all member names are the same.
 *
 *
 *
 *
 *
 *
 *
 *	struct aiocb64 [Data Type]
 *	int aio_fildes
 *	This element specifes the fle descriptor which is used for the operation.
 *	It must be a legal descriptor since otherwise the operation fails for obvious
 *	reasons.
 *	The device on which the fle is opened must allow the seek operation.
*	I.e., it is not possible to use any of the AIO operations on devices like
*	terminals where an lseek call would lead to an error.
*	off64_t aio_offset
*	This element specifes at which oﬀset in the fle the operation (input or
		*	output) is performed. Since the operation are carried in arbitrary order
*	and more than one operation for one fle descriptor can be started, one
*	cannot expect a current read/write position of the fle descriptor.
*	volatile void *aio_buf
*	This is a pointer to the buﬀer with the data to be written or the place
*	where the read data is stored.
*	size_t aio_nbytes
*	This element specifes the length of the buﬀer pointed to by aio_buf.
*	int aio_reqprio
*	If for the platform _POSIX_PRIORITIZED_IO and _POSIX_PRIORITY_
*	SCHEDULING are defned the AIO requests are processed based on the
*
*
*	current scheduling priority. The aio_reqprio element can then be used
*	to lower the priority of the AIO operation.
*	struct sigevent aio_sigevent
*	This element specifes how the calling process is notifed once the opera
*	tion terminates. If the sigev_notify, element is SIGEV_NONE no notifca
*	tion is sent. If it is SIGEV_SIGNAL, the signal determined by sigev_signo
*	is sent. Otherwise, sigev_notify must be SIGEV_THREAD in which case a
*	thread which starts executing the function pointed to by sigev_notify_
*	function.
*	int aio_lio_opcode
*	This element is only used by the lio_listio and [lio_listio64 func
*	tions. Since these functions allow an arbitrary number of operations
*	to start at once, and since each operation can be input or output (or
		*	nothing), the information must be stored in the control block. See the
*	description of struct aiocb for a description of the possible values.
*	When the sources are compiled using _FILE_OFFSET_BITS == 64 on a 32 bit machine,
	*	this type is available under the name struct aiocb64, since the LFS transparently
	*	replaces the old interface.
*
* int aio_read (struct aiocb *aiocbp) [Function]
* This function initiates an asynchronous read operation. It immediately returns after
* the operation was enqueued or when an error was encountered.
* The frst aiocbp->aio_nbytes bytes of the fle for which aiocbp->aio_fildes is a
* descriptor are written to the buﬀer starting at aiocbp->aio_buf. Reading starts at
* the absolute position aiocbp->aio_offset in the fle.
* If prioritized I/O is supported by the platform the aiocbp->aio_reqprio value is
* used to adjust the priority before the request is actually enqueued.
* The calling process is notifed about the termination of the read request according to
* the aiocbp->aio_sigevent value.
* When aio_read returns, the return value is zero if no error occurred that can be
* found before the process is enqueued. If such an early error is found, the function
* returns −1 and sets errno to one of the following values:
* EAGAIN The request was not enqueued due to (temporarily) exceeded resource
* limitations.
* ENOSYS The aio_read function is not implemented.
* EBADF The aiocbp->aio_fildes descriptor is not valid. This condition need
* not be recognized before enqueueing the request and so this error might
* also be signaled asynchronously.
* EINVAL The aiocbp->aio_offset or aiocbp->aio_reqpiro value is invalid.
* This condition need not be recognized before enqueueing the request
* and so this error might also be signaled asynchronously.
*
* If aio_read returns zero, the current status of the request can be queried using aio_
* error and aio_return functions. As long as the value returned by aio_error is
* EINPROGRESS the operation has not yet completed. If aio_error returns zero, the
* operation successfully terminated, otherwise the value is to be interpreted as an error
* code. If the function terminated, the result of the operation can be obtained using
* a call to aio_return. The returned value is the same as an equivalent call to read
* would have returned. Possible error codes returned by aio_error are:
* EBADF The aiocbp->aio_fildes descriptor is not valid.
* ECANCELED
* The operation was canceled before the operation was fnished (see
		* Section 13.10.4 [Cancellation of AIO Operations], page 327)
* EINVAL The aiocbp->aio_offset value is invalid.
* When the sources are compiled with _FILE_OFFSET_BITS == 64 this function is in
* fact aio_read64 since the LFS interface transparently replaces the normal imple
* mentation.
* int aio_read64 (struct aiocb *aiocbp) [Function]
* This function is similar to the aio_read function. The only diﬀerence is that on 32 bit
* machines, the fle descriptor should be opened in the large fle mode. Internally, aio_
* read64 uses functionality equivalent to lseek64 (see Section 13.3 [Setting the File
		* Position of a Descriptor], page 303) to position the fle descriptor correctly for the
* reading, as opposed to lseek functionality used in aio_read.
* When the sources are compiled with _FILE_OFFSET_BITS == 64, this function is avail
* able under the name aio_read and so transparently replaces the interface for small
* fles on 32 bit machines.
* To write data asynchronously to a fle, there exists an equivalent pair of functions with
* a very similar interface.
* int aio_write (struct aiocb *aiocbp) [Function]
* This function initiates an asynchronous write operation. The function call immedi
* ately returns after the operation was enqueued or if before this happens an error was
* encountered.
* The frst aiocbp->aio_nbytes bytes from the buﬀer starting at aiocbp->aio_buf
* are written to the fle for which aiocbp->aio_fildes is an descriptor, starting at the
* absolute position aiocbp->aio_offset in the fle.
* If prioritized I/O is supported by the platform, the aiocbp->aio_reqprio value is
* used to adjust the priority before the request is actually enqueued.
* The calling process is notifed about the termination of the read request according to
* the aiocbp->aio_sigevent value.
* When aio_write returns, the return value is zero if no error occurred that can be
* found before the process is enqueued. If such an early error is found the function
* returns −1 and sets errno to one of the following values.
* EAGAIN The request was not enqueued due to (temporarily) exceeded resource
* limitations.
*
* ENOSYS The aio_write function is not implemented.
* EBADF The aiocbp->aio_fildes descriptor is not valid. This condition may
* not be recognized before enqueueing the request, and so this error might
* also be signaled asynchronously.
* EINVAL The aiocbp->aio_offset or aiocbp->aio_reqprio value is invalid.
* This condition may not be recognized before enqueueing the request and
* so this error might also be signaled asynchronously.
* In the case aio_write returns zero, the current status of the request can be queried
* using aio_error and aio_return functions. As long as the value returned by aio_
* error is EINPROGRESS the operation has not yet completed. If aio_error returns
* zero, the operation successfully terminated, otherwise the value is to be interpreted
* as an error code. If the function terminated, the result of the operation can be get
* using a call to aio_return. The returned value is the same as an equivalent call to
* read would have returned. Possible error codes returned by aio_error are:
* EBADF The aiocbp->aio_fildes descriptor is not valid.
* ECANCELED
* The operation was canceled before the operation was fnished. (see
		* Section 13.10.4 [Cancellation of AIO Operations], page 327)
* EINVAL The aiocbp->aio_offset value is invalid.
* When the sources are compiled with _FILE_OFFSET_BITS == 64, this function is in
* fact aio_write64 since the LFS interface transparently replaces the normal imple
* mentation.
* int aio_write64 (struct aiocb *aiocbp) [Function]
* This function is similar to the aio_write function. The only diﬀerence is that on
* 32 bit machines the fle descriptor should be opened in the large fle mode. Internally
* aio_write64 uses functionality equivalent to lseek64 (see Section 13.3 [Setting the
		* File Position of a Descriptor], page 303) to position the fle descriptor correctly for
* the writing, as opposed to lseek functionality used in aio_write.
* When the sources are compiled with _FILE_OFFSET_BITS == 64, this function is avail
* able under the name aio_write and so transparently replaces the interface for small
* fles on 32 bit machines.
* Besides these functions with the more or less traditional interface, POSIX.1b also defnes
* a function which can initiate more than one operation at a time, and which can handle
* freely mixed read and write operations. It is therefore similar to a combination of readv
* and writev.
*/

#include <aio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <malloc.h>


int aio_read (struct aiocb *aiocbp);


int main()
{
	int fd, ret;
	struct aiocb my_aiocb;

	fd = open("journal.log", O_RDONLY);

	if(fd < 0)
	{
		perror("open;");
	}
	bzero((char*)&my_aiocb, sizeof(struct aiocb));

	my_aiocb.aio_buf = malloc(100+1);

	if(!my_aiocb.aio_buf)
	{
		perror("malloc");
	}	
	my_aiocb.aio_fildes = fd;
	my_aiocb.aio_nbytes = 100;
	my_aiocb.aio_offset = 0;
	
	ret = aio_read(&my_aiocb);

	printf(":%s\n", my_aiocb.aio_buf);


	if(ret < 0)
	{
		perror("aio_read");
	}

	//while(aio_error(&my_aiocb) == EINPROGRESS);
	while(aio_error(&my_aiocb) == 0);

	if((ret = aio_return(&my_aiocb)) > 0)
	{
		printf("Success Return\n");
	}
	else
	{
		printf("return Failed\n");
	}

	return 0;
}
