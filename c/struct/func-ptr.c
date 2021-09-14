#include <stdio.h>
#include <stdlib.h>

#define debug() printf("%s: %d %s\n", __FILE__, __LINE__, __func__)



struct funcs {
	int init(void *arg);
	int close();

} Functions = {
#if 0
	.init(void *arg)
	{
		return debug();
	}
	.close()
	{
		return debug();
	}
#endif
};


int main()
{
	Functions.init(NULL);

	return 0;
}
