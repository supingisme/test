/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:42 CST. */
#include <stdio.h>

struct fpga_hwaddr {
	char hwaddr[8];
};

struct fpgas {
	struct fpga_hwaddr hwaddr[5];
};

struct cell {
	int rru_id;
	//static struct fpgas fpgas; //forbidden use static here.
};

int main()
{
	return 0;
}
