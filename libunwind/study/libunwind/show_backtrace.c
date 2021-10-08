#include <stdio.h>

#define UNW_LOCAL_ONLY
#include <libunwind.h>

void show_backtrace (void) 
{
	unw_cursor_t cursor; unw_context_t uc;
	unw_word_t ip, sp;

	//get snap shot of CPU  register 
	unw_getcontext(&uc);

	//
	unw_init_local(&cursor, &uc);

	//
	while (unw_step(&cursor) > 0) {
		unsigned long offset;
		char fname[128];

		unw_get_reg(&cursor, UNW_REG_IP, &ip);
		unw_get_reg(&cursor, UNW_REG_SP, &sp);
		
		unw_get_proc_name(&cursor, fname, sizeof(fname), &offset);

		printf ("ip = %lx, sp = %lx, fname = %s+0x%lx\n", (long) ip, (long) sp, fname, offset);
	}
}

int func1()
{
	show_backtrace();
}

int main()
{
	func1();
}
