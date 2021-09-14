#include <stdio.h>

struct rru {
	int rruid;
};

struct cell {
	int cellid;
	struct rru *rru;
};

struct rru rrus[2] = {
	{1}, {2} //两个RRU
};

struct cell cells[2] = {
	{1,}, {2,} //两个小区，
};

int main ()
{
	cells[0].rru = &rrus;
	cells[1].rru = &rrus;

	printf("小区1的第一个RRU id=%d\n", cells[0].rru[0].rruid);
	printf("小区1的第二个RRU id=%d\n", cells[0].rru[1].rruid);


}
