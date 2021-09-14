#include <stdio.h>

#define tostring(v) printf("%s = %d\n", #v, v);

struct rong {
	int tao;
};

int main()
{
	struct rong rong;
	rong.tao = 10;

	tostring(rong.tao);

	return 0;
}
