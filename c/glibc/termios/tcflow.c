/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:32 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:34 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:06 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:18 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:55 CST. */
/*
17.6 Line Control Functions
These functions perform miscellaneous control actions on terminal devices. As regards
terminal access, they are treated like doing output: if any of these functions is used by
a background process on its controlling terminal, normally all processes in the process
group are sent a SIGTTOU signal. The exception is if the calling process itself is ignoring or
blocking SIGTTOU signals, in which case the operation is performed and no signal is sent.
See Chapter 27 [Job Control], page 699.
int tcsendbreak (int filedes, int duration) [Function]
This function generates a break condition by transmitting a stream of zero bits on
the terminal associated with the fle descriptor fledes. The duration of the break is
controlled by the duration argument. If zero, the duration is between 0.25 and 0.5
seconds. The meaning of a nonzero value depends on the operating system.
This function does nothing if the terminal is not an asynchronous serial data port.
The return value is normally zero. In the event of an error, a value of −1 is returned.
The following errno error conditions are defned for this function:
EBADF The fledes is not a valid fle descriptor.
ENOTTY The fledes is not associated with a terminal device.
int tcdrain (int filedes) [Function]
The tcdrain function waits until all queued output to the terminal fledes has been
transmitted.
This function is a cancellation point in multi-threaded programs. This is a problem
if the thread allocates some resources (like memory, fle descriptors, semaphores or
whatever) at the time tcdrain is called. If the thread gets canceled these resources
stay allocated until the program ends. To avoid this calls to tcdrain should be
protected using cancellation handlers.
The return value is normally zero. In the event of an error, a value of −1 is returned.
The following errno error conditions are defned for this function:
EBADF The fledes is not a valid fle descriptor.
ENOTTY The fledes is not associated with a terminal device.
EINTR The operation was interrupted by delivery of a signal. See Section 24.5
[Primitives Interrupted by Signals], page 628.
int tcflush (int filedes, int queue) [Function]
The tcflush function is used to clear the input and/or output queues associated with
the terminal fle fledes. The queue argument specifes which queue(s) to clear, and
can be one of the following values:
TCIFLUSH
Clear any input data received, but not yet read.
TCOFLUSH
Clear any output data written, but not yet transmitted.
TCIOFLUSH
Clear both queued input and output.
The return value is normally zero. In the event of an error, a value of −1 is returned.
The following errno error conditions are defned for this function:
EBADF The fledes is not a valid fle descriptor.
ENOTTY The fledes is not associated with a terminal device.
EINVAL A bad value was supplied as the queue argument.
It is unfortunate that this function is named tcflush, because the term “ﬂush” is
normally used for quite another operation—waiting until all output is transmitted—
and using it for discarding input or output would be confusing. Unfortunately, the
name tcflush comes from POSIX and we cannot change it.
int tcflow (int filedes, int action) [Function]
The tcflow function is used to perform operations relating to XON/XOFF ﬂow
control on the terminal fle specifed by fledes.
The action argument specifes what operation to perform, and can be one of the
following values:
TCOOFF Suspend transmission of output.
TCOON Restart transmission of output.
TCIOFF Transmit a STOP character.
TCION Transmit a START character.
For more information about the STOP and START characters, see Section 17.4.9
[Special Characters], page 446.
The return value is normally zero. In the event of an error, a value of −1 is returned.
The following errno error conditions are defned for this function:
EBADF The fledes is not a valid fle descriptor.
ENOTTY The fledes is not associated with a terminal device.
EINVAL A bad value was supplied as the action argument.
*/
#include <termios.h>
//串口：串行接口
int tcsendbreak (int filedes, int duration);
int tcdrain (int filedes);  //等待直到所有写入fd引用的对象的输出都被传输
int tcflush (int filedes, int queue); //苏哈晴输入缓存
int tcflow (int filedes, int action);   //挂起传输或接受
