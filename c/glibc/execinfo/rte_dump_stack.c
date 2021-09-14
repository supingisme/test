#include <stdio.h>
#include <execinfo.h>

#define RTE_BACKTRACE
#define BACKTRACE_SIZE 100
#define rte_log(level,type, fmt...) printf(fmt)

/* dump the stack of the calling core */
void rte_dump_stack(void)
{
#ifdef RTE_BACKTRACE
	void *func[BACKTRACE_SIZE];
	char **symb = NULL;
	int size;

	size = backtrace(func, BACKTRACE_SIZE);
	symb = backtrace_symbols(func, size);

	if (symb == NULL)
		return;

	while (size > 0) {
		rte_log(RTE_LOG_ERR, RTE_LOGTYPE_EAL, "%d: [%s]\n", size, symb[size - 1]);
		size --;
	}

	free(symb);
#endif /* RTE_BACKTRACE */
}

void demo1()
{
	rte_dump_stack();
}

int main()
{
	demo1();

	return 0;
}
