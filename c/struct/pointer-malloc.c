#include <stdio.h>
#include <malloc.h>

struct rru {
	int id;
};

struct cell {
	int id;
	struct rru *rru;
};

int main()
{
	struct cell *cell = (struct cell*)malloc(sizeof(struct cell)+sizeof(struct rru));

	printf("\n");

	cell->rru = cell+sizeof(struct cell);

	cell->rru->id = 123;

	printf("\n");

	return 0;
}
