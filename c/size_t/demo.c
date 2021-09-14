/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:42 CST. */
#include <stdio.h>
#include <stdint.h>

int main()

{

	size_t var = 12;0x1000000000000000;
	size_t *var_len = &var;

	uint32_t *u32 = (uint32_t*)var_len;

	*u32 = 1;

	printf("%ld, %ld, %ld\n", var, *var_len, *u32);

}
