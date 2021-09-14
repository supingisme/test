Kernel Memory Allocator
The Kernel Memory Allocator (KMA) is a subsystem that tries to satisfy the requests for memory
areas from all parts of the system. Some of these requests come from other kernel subsystems
needing memory for kernel use, and some requests come via system calls from user programs to
increase their processes' address spaces.

-------------------------
A good KMA should have the following features:
It must be fast. Actually, this is the most crucial attribute, because it is invoked by all kernel
	subsystems (including the interrupt handlers).
It should minimize the amount of wasted memory.
It should try to reduce the memory fragmentation problem.
It should be able to cooperate with the other memory management subsystems to borrow
	and release page frames from them.


--------------------------
Several proposed KMAs, which are based on a variety of different algorithmic techniques, include:
Resource map allocator
Power-of-two free lists
McKusick-Karels allocator
Buddy system
Mach's Zone allocator
Dynix allocator
Solaris 's Slab allocator
