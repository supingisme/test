16.5 The Local Namespace
This section describes the details of the local namespace, whose symbolic name (required
when you create a socket) is PF_LOCAL. The local namespace is also known as “Unix domain
sockets”. Another name is fle namespace since socket addresses are normally implemented
as fle names.
16.5.1 Local Namespace Concepts
In the local namespace socket addresses are fle names. You can specify any fle name you
want as the address of the socket, but you must have write permission on the directory
containing it. It’s common to put these fles in the ‘/tmp’ directory.
One peculiarity of the local namespace is that the name is only used when opening the
connection; once open the address is not meaningful and may not exist.
Another peculiarity is that you cannot connect to such a socket from another machine–
not even if the other machine shares the fle system which contains the name of the socket.
You can see the socket in a directory listing, but connecting to it never succeeds. Some
programs take advantage of this, such as by asking the client to send its own process ID, and
using the process IDs to distinguish between clients. However, we recommend you not use
this method in protocols you design, as we might someday permit connections from other
machines that mount the same fle systems. Instead, send each new client an identifying
number if you want it to have one.
After you close a socket in the local namespace, you should delete the fle name from the
fle system. Use unlink or remove to do this; see Section 14.6 [Deleting Files], page 359.
The local namespace supports just one protocol for any communication style; it is pro
tocol number 0.

16.5.2 Details of Local Namespace
To create a socket in the local namespace, use the constant PF_LOCAL as the namespace
argument to socket or socketpair. This constant is defned in ‘sys/socket.h’.
int PF_LOCAL [Macro]
This designates the local namespace, in which socket addresses are local names, and
its associated family of protocols. PF_Local is the macro used by Posix.1g.
int PF_UNIX [Macro]
This is a synonym for PF_LOCAL, for compatibility’s sake.
int PF_FILE [Macro]
This is a synonym for PF_LOCAL, for compatibility’s sake

struct sockaddr_un [Data Type]
This structure is used to specify local namespace socket addresses. It has the following
members:
short int sun_family
This identifes the address family or format of the socket address. You
should store the value AF_LOCAL to designate the local namespace. See
Section 16.3 [Socket Addresses], page 391.
char sun_path[108]
This is the fle name to use.
Incomplete: Why is 108 a magic number? RMS suggests making this
a zero-length array and tweaking the following example to use alloca
to allocate an appropriate amount of storage based on the length of the
flename.
You should compute the length parameter for a socket address in the local namespace as
the sum of the size of the sun_family component and the string length (not the allocation
size!) of the fle name string. This can be done using the macro SUN_LEN:
int SUN_LEN (struct sockaddr un * ptr) [Macro]
The macro computes the length of socket address in the local namespace.