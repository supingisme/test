/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:30 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:33 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:04 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:17 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:54 CST. */
/**
 *	使用sysctl函数检查路由表和接口列表	
 *		
 *		P393
 */

#include <sys/param.h>
#include <sys/sysctl.h>

int sysctl(int *name, u_int namelen, void *oldp, size_t *oldlenp,
					void *newp, size_t newlen);
int main()
{
 int mib[4], val;
 size_t len;
 mib[0] = CTL_NET;
 mib[1] = AF_INET;
 mib[2] = IPPROTO_UDP;
 mib[3] = UDPCTL_CHECKSUM;
 len = sizeof(val);
 Sysctl(mib, 4, &val, &len, NULL, 0);
 printf("udp checksum flag: %d\n", val);
 exit(0) ;
}

/**
 *	这个函数使用类似简单网络管理协议SNMP中管理信息库MIB的名字。
 *
 *	name：指定名字的一个整数数组；
 *	namelen：指定该数组中的元素个数
 *			该数组中的第一个元素指定本请求定向到内核的哪个子系统
 *
 */

/*
 *	int sysctl (int *names, int nlen, void *oldval, size t *oldlenp, void [Function]
 *	*newval, size t newlen)
 *	sysctl gets or sets a specifed system parameter. There are so many of these param
 *	eters that it is not practical to list them all here, but here are some examples:
 *	• network domain name
 *	• paging parameters
 *	• network Address Resolution Protocol timeout time
 *	• maximum number of fles that may be open
 *	• root flesystem device
 *	• when kernel was built
 *	The set of available parameters depends on the kernel confguration and can change
 *	while the system is running, particularly when you load and unload loadable kernel
 *	modules.
 *	The system parameters with which syslog is concerned are arranged in a hierarchical
 *	structure like a hierarchical flesystem. To identify a particular parameter, you specify
 *	a path through the structure in a way analogous to specifying the pathname of a fle.
 *	Each component of the path is specifed by an integer and each of these integers has
 *	a macro defned for it by ‘sysctl.h’. names is the path, in the form of an array of
 *	integers. Each component of the path is one element of the array, in order. nlen is
 *	the number of components in the path.
 *	For example, the frst component of the path for all the paging parameters is the
 *	value CTL_VM. For the free page thresholds, the second component of the path is
 *	VM_FREEPG. So to get the free page threshold values, make names an array containing
 *	the two elements CTL_VM and VM_FREEPG and make nlen = 2.
 *	The format of the value of a parameter depends on the parameter. Sometimes it is
 *	an integer; sometimes it is an ASCII string; sometimes it is an elaborate structure. In
 *	the case of the free page thresholds used in the example above, the parameter value
 *	is a structure containing several integers.
 *	In any case, you identify a place to return the parameter’s value with oldval and
 *	specify the amount of storage available at that location as *oldlenp. *oldlenp does
 *	double duty because it is also the output location that contains the actual length of
 *	the returned value.
 *	If you don’t want the parameter value returned, specify a null pointer for oldval.
 *	To set the parameter, specify the address and length of the new value as newval and
 *	newlen. If you don’t want to set the parameter, specify a null pointer as newval.
 *	If you get and set a parameter in the same sysctl call, the value returned is the value
 *	of the parameter before it was set.
 *	Each system parameter has a set of permissions similar to the permissions for a fle
 *	(including the permissions on directories in its path) that determine whether you may
 *	get or set it. For the purposes of these permissions, every parameter is considered to
 *	be owned by the superuser and Group 0 so processes with that eﬀective uid or gid
 *	may have more access to system parameters. Unlike with fles, the superuser does
 *	not invariably have full permission to all system parameters, because some of them
 *	are designed not to be changed ever.
 *	sysctl returns a zero return value if it succeeds. Otherwise, it returns -1 and sets
 *	errno appropriately. Besides the failures that apply to all system calls, the following
 *	are the errno codes for all possible failures:
 *	EPERM The process is not permitted to access one of the components of the
 *	path of the system parameter or is not permitted to access the system
 *	parameter itself in the way (read or write) that it requested.
 *	ENOTDIR There is no system parameter corresponding to name.
 *	EFAULT oldval is not null, which means the process wanted to read the parameter,
 *	but *oldlenp is zero, so there is no place to return it.
 *	EINVAL
 *	• The process attempted to set a system parameter to a value that is
 *	not valid for that parameter.
 *
 *	• The space provided for the return of the system parameter is not the
 *	right size for that parameter.
 *	ENOMEM This value may be returned instead of the more correct EINVAL in some
 *	cases where the space provided for the return of the system parameter is
 *	too small.
 *	If you have a Linux kernel with the proc flesystem, you can get and set most of the
 *	same parameters by reading and writing to fles in the sys directory of the proc flesystem.
 *	In the sys directory, the directory structure represents the hierarchical structure of the
 *	parameters. E.g. you can display the free page thresholds with
 *	cat /proc/sys/vm/freepages
 *	Some more traditional and more widely available, though less general, GNU C library
 *	functions for getting and setting some of the same system parameters are:
 *	• getdomainname, setdomainname
*	• gethostname, sethostname (See Section 30.1 [Host Identifcation], page 754.)
	*	• uname (See Section 30.2 [Platform Type Identifcation], page 756.)
	*	• bdflush
	*
 */
#include <sysctl.h>

int sysctl (int *names, int nlen, void *oldval, size_t *oldlenp, void
		*newval, size_t newlen);

int main()
{
	


	return 0;
}

