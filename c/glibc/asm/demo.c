/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 18日 星期二 08:46:20 CST. */


#include <stdio.h>

#define PI	3.1415926

int main()
{
	//asm ("shrl $8, %0" : "=r" (answer) : "r" (operand) : "cc");
	float answer;
	float angle = (PI/2);
	asm ("fsin" : "=t"(answer) : "0" (angle));
	printf("fsin(%f) = %f\n", angle, answer);
	return 0;
}
