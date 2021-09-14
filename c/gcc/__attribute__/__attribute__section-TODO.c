#include <stdio.h>
#include <stdlib.h>

#define debug() printf("%s:%d %s\n", __FILE__, __LINE__, __func__)

typedef void (*init_call)(void);

#define _init __attribute__((unused, section(".myinit")))

#define DECLARE_INIT(func) init_call _fn_##func _init = func

/*
 *  * These two variables are defined in link script.
 */
//extern init_call _init_start;
//extern init_call _init_end;

static void A_init(void)
{
	debug();
    write(1, "A_init\n", sizeof("A_init\n"));
}
DECLARE_INIT(A_init);

static void B_init(void)
{
	debug();
}
DECLARE_INIT(B_init);

static void C_init(void)
{
	debug();
}
DECLARE_INIT(C_init);

void do_initcalls(void)
{

    init_call *init_ptr = &A_init;//&_init_start;

    for (; init_ptr < &C_init/*_init_end*/; init_ptr++) 
	{
        printf("init address: %p\n", init_ptr);
        (*init_ptr)();
	}
}

int main()
{
	do_initcalls();
	return 0;
}

