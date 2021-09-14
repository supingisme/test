#include <stdio.h>

typedef struct rong_tao_s {
	int age;
	long life_long;
}rt_t, *prt_t;

int main()
{
	prt_t prt;
	rt_t *rt = NULL;

	printf("%d, %d, %d, %d\n", sizeof(prt), sizeof(*prt), sizeof(rt), sizeof(*rt));
}
