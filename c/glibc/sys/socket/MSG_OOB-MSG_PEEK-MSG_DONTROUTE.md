16.9.5.3 Socket Data Options
The ﬂags argument to send and recv is a bit mask. You can bitwise-OR the values of the
following macros together to obtain a value for this argument. All are defned in the header
fle ‘sys/socket.h’.

int MSG_OOB [Macro]
Send or receive out-of-band data. See Section 16.9.8 [Out-of-Band Data], page 422.

int MSG_PEEK [Macro]
Look at the data but don’t remove it from the input queue. This is only meaningful
with input functions such as recv, not with send.

int MSG_DONTROUTE [Macro]
Don’t include routing information in the message. This is only meaningful with
output operations, and is usually only of interest for diagnostic or routing programs.
We don’t try to explain it here.


see it in send.c and recv.c
