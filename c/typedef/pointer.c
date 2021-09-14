#include <stdio.h>
#include <malloc.h>

typedef struct cell {
	int id;
	struct cell *next;
	struct cell *prev;
}cell_t, *pcell_t;

pcell_t cell_init(int id)
{
	pcell_t pc = malloc(sizeof(struct cell));
	pc->id = id;
	pc->next = NULL;
	pc->prev = NULL;

	return pc;
}

int main()
{
	pcell_t pc1 = malloc(sizeof(struct cell));

	cell_t *pc2 = malloc(sizeof(struct cell));

	typeof(pc2) pc3 = malloc(sizeof(struct cell));

	pcell_t pc4 = cell_init(12);

	printf("id = %d\n", pc4->id);
	
	free(pc4);

	return 0;
}
