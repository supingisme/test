#include <stdio.h>
#include <stdint.h>

#define _packed __attribute__((packed))

#define ED2(_1, _2) (_1, _2)_packed

typedef struct cell_id_s {
	uint8_t i1:1;
	uint8_t i2:2;
	uint64_t i3:35;
	uint64_t i4:36;
}_packed cell_id_t;


int main()
{
	printf("%d\n", sizeof(cell_id_t));

	return 0;
}
