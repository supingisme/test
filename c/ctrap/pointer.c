#include <stdio.h>

int main(void)
{
	int x=100,y=20,res;
	int *p,p1;
	int *q;
	p=&x;
	q=&y;
	p1=p;

	res = *p / *q;

	/* redirect access  */
	*p1++;
	printf("res=%d\n",res);


	return 0;
}
