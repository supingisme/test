/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	int fd;
	int pid;
}cell_t;

cell_t cells[] = 
{
	{1,2,3},
	{2,3,2},
	{1,1,1},
};

int show_cell(cell_t *cells, int num)
{
	if (cells == NULL)
	{
		printf("NULL pointer error.\n");
		return -1;
	}
	printf("--------------num = %d\n", num);
	int i;
	for(i=0;i<num;i++)
		printf("id = %2d, fd = %2d, pid = %3d\n", 
				cells[i].id, cells[i].fd, cells[i].pid);
	return 0;
}

int cmp_cell(void *l, void *r)
{
	return memcmp(l, r, sizeof(cell_t));
}

int main()
{
	show_cell(cells, sizeof(cells)/sizeof(cell_t));

	cell_t *cell_item = NULL;

	cell_t cell = {2,3,2};

	int cmp_c(const void *l, const void *r)
	{
		return memcmp(l, r, sizeof(cell_t));
	}

	cell_item = bsearch(&cell, cells, sizeof(cells)/sizeof(cell_t), sizeof(cell_t),
						&cmp_c);
	printf("item : %p\n", cell_item);
	show_cell(cells, sizeof(cells)/sizeof(cell_t));

	show_cell(cell_item, 1);

	//free(cell_item);

	printf("%p:%p\n", cell_item, &cells[1]);

	return 0;
}
