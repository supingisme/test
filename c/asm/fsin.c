#include <math.h>
#include <stdio.h>

int main()
{
	float answer, angle;

	angle = 3.1415926f/6;

	asm ("fsin" : "=t" (answer) : "0" (angle));

	printf("fsin(%f) = %f\n", angle, answer);
}
