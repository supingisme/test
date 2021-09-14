16.6 The Internet Namespace
This section describes the details of the protocols and socket naming conventions used in
the Internet namespace.
Originally the Internet namespace used only IP version 4 (IPv4). With the growing
number of hosts on the Internet, a new protocol with a larger address space was necessary:
IP version 6 (IPv6). IPv6 introduces 128-bit addresses (IPv4 has 32-bit addresses) and
other features, and will eventually replace IPv4.
To create a socket in the IPv4 Internet namespace, use the symbolic name PF_INET of
this namespace as the namespace argument to socket or socketpair. For IPv6 addresses
you need the macro PF_INET6. These macros are defned in ‘sys/socket.h’.
int PF_INET [Macro]
This designates the IPv4 Internet namespace and associated family of protocols.
int PF_INET6 [Macro]
This designates the IPv6 Internet namespace and associated family of protocols.
A socket address for the Internet namespace includes the following components:
• The address of the machine you want to connect to. Internet addresses can be specifed
in several ways; these are discussed in Section 16.6.1 [Internet Socket Address Formats],
page 397, Section 16.6.2 [Host Addresses], page 398 and Section 16.6.2.4 [Host Names],
page 402.
• A port number for that machine. See Section 16.6.3 [Internet Ports], page 406.
You must ensure that the address and port number are represented in a canonical for
mat called network byte order. See Section 16.6.5 [Byte Order Conversion], page 408, for
information about this.
