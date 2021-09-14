#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct test {
	int id;
	char data[0];
};

struct msg1 {
	int type;
};

int main()
{
    printf("sizeof struct test = %d\n", sizeof(struct test));

	struct test *test = (struct test*)malloc(sizeof(struct test) + sizeof(struct msg1));
	struct msg1 msg1 = {11115};
	test->id = 10;
	memcpy(test->data, &msg1, sizeof(struct msg1));

	struct msg1 *pmsg1 = test->data;

	printf("%d\n", pmsg1->type);

	return 0;
}
