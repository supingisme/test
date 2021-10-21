#include <stdio.h>
#include <sys/ucontext.h>

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

int main()
{
#define S	sizeof(ucontext_t)
	printf("%d, %lx\n", S, S);
	printf("offset of uc_stack.ss_sp = 0x%lx\n", offsetof(ucontext_t, uc_stack.ss_sp));
	printf("offset of uc_stack.ss_size = 0x%lx\n", offsetof(ucontext_t, uc_stack.ss_size));
}
