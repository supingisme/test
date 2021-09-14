/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:27 CST. */

#include <stdio.h>

#define __user		__attribute__((noderef, address_space(1)))


int main()
{
	int  __user *a;
	
	return 0;
}
