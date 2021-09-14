/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
#include <stdio.h>
#include <stdlib.h>

/**
 * stdlib.h
 *	typedef int (*__compar_fn_t) (const void *, const void *);
 */
int cmp1(int *r, int *s)
{
	int diff = *r - *s;

	if      (diff > 0)	return(1);
	else if (diff < 0)	return(-1);
	else  /* diff == 0 */	return(0);
}

int array[] = 
{
	12,23,12,2,1,3,2,4,5,5,5,243,2,4,243,1,23,413,24,3,42,4524,35,24,5,24,
};

int show(int *arr, int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%d, ", arr[i]);
	printf("\n");
}

struct cell_t {
	int id;
	int fd;
	int pid;
}__attribute__((packed));

struct cell_t cells[] = {
	{1,2,3},
	{1,2,2},
	{1,1,1},
	{2,1,3},
	{1,2,0},
	{4,1,2},
	{1,1,1},
};

int cmp_cell(void *l, void *r)
{
	return memcmp(l, r, sizeof(struct cell_t));
}

int show_cell(struct cell_t *cells, int num)
{
	printf("--------------num = %d\n", num);
	int i;
	for(i=0;i<num;i++)
		printf("id = %2d, fd = %2d, pid = %3d\n", 
				cells[i].id, cells[i].fd, cells[i].pid);
}

int main()
{
	show(array, sizeof(array)/sizeof(int));

	qsort(array, sizeof(array)/sizeof(int), sizeof(int), &cmp1);

	show(array, sizeof(array)/sizeof(int));

	show_cell(cells, sizeof(cells)/sizeof(struct cell_t));

	qsort(cells, sizeof(cells)/sizeof(struct cell_t), sizeof(struct cell_t), &cmp_cell);

	show_cell(cells, sizeof(cells)/sizeof(struct cell_t));




}
