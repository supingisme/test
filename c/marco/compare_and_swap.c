#include <stdio.h>

#define _val_compare_and_swap(ptr, oldval, newold) __sync_val_compare_and_swap(ptr, oldval, newold)

#define OK		11
#define NOTOK	10

static int flag = NOTOK;

int main()
{
	printf("flag = %d,", flag);
	printf(" cas = %d, ", _val_compare_and_swap(&flag, flag, OK));
	printf(" flag = %d\n", flag);

	printf("flag = %d,", flag);
	printf(" cas = %d, ", _val_compare_and_swap(&flag, flag, OK));
	printf(" flag = %d\n", flag);

	printf("flag = %d,", flag);
	printf(" cas = %d, ", _val_compare_and_swap(&flag, flag, OK));
	printf(" flag = %d\n", flag);

#if 0
	printf("flag = %d, cas = %d, -> %d\n", flag, _val_compare_and_swap(&flag, flag, OK), flag);
	printf("flag = %d, cas = %d, -> %d\n", flag, _val_compare_and_swap(&flag, flag, OK), flag);
	printf("flag = %d, cas = %d, -> %d\n", flag, _val_compare_and_swap(&flag, flag, NOTOK), flag);
#endif
	return 0;
}
