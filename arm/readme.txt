# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:03 CST. 
Rong Tao 2019.06.11



1.source code
```c
#include <stdio.h>
int factorial(int n) {
	if (n == 0)
		return 1;
	return n * factorial (n - 1);
}
int main () {
	int i;
	int n;
	for (i = 0; i < 10; ++i) {
		n = factorial (i);
		printf ("factorial(%d) = %d\n", i, n);
	}
	return 0;
}
```

2.Compile and link this program using the command:
> powerpc-linux-gnu-gcc -o factorial main.c

3.To run your program on a GNU/Linux target system, use the command:
> factorial

4.Running Applications from GDB
> powerpc-linux-gnu-gdb factorial



