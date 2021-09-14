16.2 Communication Styles
The GNU library includes support for several diﬀerent kinds of sockets, each with diﬀerent
characteristics. This section describes the supported socket types. The symbolic constants
listed here are defned in ‘sys/socket.h’.


int SOCK_STREAM [Macro]
The SOCK_STREAM style is like a pipe (see Chapter 15 [Pipes and FIFOs], page 384).
It operates over a connection with a particular remote socket and transmits data
reliably as a stream of bytes.
Use of this style is covered in detail in Section 16.9 [Using Sockets with Connections],
	page 413.
