16.12.2 Socket-Level Options
int SOL_SOCKET [Constant]
Use this constant as the level argument to getsockopt or setsockopt to manipulate
the socket-level options described in this section.
Here is a table of socket-level option names; all are defned in the header fle ‘sys/socket.h’.
SO_DEBUG
This option toggles recording of debugging information in the underlying pro
tocol modules. The value has type int; a nonzero value means “yes”.
SO_REUSEADDR
This option controls whether bind (see Section 16.3.2 [Setting the Address of a
		Socket], page 393) should permit reuse of local addresses for this socket. If you
enable this option, you can actually have two sockets with the same Internet
port number; but the system won’t allow you to use the two identically-named
sockets in a way that would confuse the Internet. The reason for this option is
that some higher-level Internet protocols, including FTP, require you to keep
reusing the same port number.
The value has type int; a nonzero value means “yes”.
SO_KEEPALIVE
This option controls whether the underlying protocol should periodically trans
mit messages on a connected socket. If the peer fails to respond to these mes
sages, the connection is considered broken. The value has type int; a nonzero
value means “yes”.
SO_DONTROUTE
This option controls whether outgoing messages bypass the normal message
routing facilities. If set, messages are sent directly to the network interface
instead. The value has type int; a nonzero value means “yes”.
SO_LINGER
This option specifes what should happen when the socket of a type that
promises reliable delivery still has untransmitted messages when it is closed;
see Section 16.8.2 [Closing a Socket], page 412. The value has type struct
linger.
struct linger [Data Type]
This structure type has the following members:
int l_onoff
This feld is interpreted as a boolean. If nonzero, close
blocks until the data are transmitted or the timeout period
has expired.
int l_linger
This specifes the timeout period, in seconds.
SO_BROADCAST
This option controls whether datagrams may be broadcast from the socket. The
value has type int; a nonzero value means “yes”.
SO_OOBINLINE
If this option is set, out-of-band data received on the socket is placed in the
normal input queue. This permits it to be read using read or recv without
specifying the MSG_OOB ﬂag. See Section 16.9.8 [Out-of-Band Data], page 422.
The value has type int; a nonzero value means “yes”.
SO_SNDBUF
This option gets or sets the size of the output buﬀer. The value is a size_t,
	 which is the size in bytes.
	 SO_RCVBUF
	 This option gets or sets the size of the input buﬀer. The value is a size_t,
	 which is the size in bytes.
	 SO_STYLE
	 SO_TYPE This option can be used with getsockopt only. It is used to get the socket’s
	 communication style. SO_TYPE is the historical name, and SO_STYLE is the
	 preferred name in GNU. The value has type int and its value designates a
	 communication style; see Section 16.2 [Communication Styles], page 390.
	 SO_ERROR
	 This option can be used with getsockopt only. It is used to reset the error
	 status of the socket. The value is an int, which represents the previous error
	 status.
