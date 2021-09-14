#include <stdio.h>
#include "init.h"

void do_initcalls(void)
{
    init_call *call_ptr = &init_start;
    while (call_ptr && call_ptr < &init_end) 
	{
        init_log ("call_ptr: %p\n", call_ptr);
        (*call_ptr)();
        ++call_ptr;
    };
}

