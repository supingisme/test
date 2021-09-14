#include <stdio.h>
#include <stdlib.h>

typedef int(*handler)(int id);

typedef struct __struct {
	int id;
	handler h;
}s_t;

static int __h(int id)
{
	return printf("%s:%d id = %d\n", __func__, __LINE__, id);
}
int fun1(handler *h)
{
	*h = &__h;
	(*h)(1);
	return 0;
}
int fun2(int (**h)(int id))
{
	*h = &__h;
	(*h)(1);
	return 0;
}

int main()
{
	handler h = NULL;

	fun1(&h);

	if(h)
		h(12);

	h = NULL;
	fun2(&h);
	if(h)
		h(12);

	return 0;
}
