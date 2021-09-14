#ifndef __INIT_H
#define __INIT_H 1

#ifdef __INIT_LOG 
#include <stdio.h>
#define init_log(fmt...) ({ \
		int n = 0;\
		n+=fprintf(stdout, "[INIT] %s %s:%d ", __FILE__, __func__, __LINE__);\
		n+=fprintf(stdout, fmt);\
		n;\
	})
#else
#define init_log(fmt...)
#endif

#define _section(StrName) __attribute__((section(StrName)))

#define INIT_FN_SECTION		".rongtao.init.func"

#define _initfn		_section(INIT_FN_SECTION)

#define INIT_ADD(func) init_call __initfn_##func _initfn = func

typedef int (*init_call)(void);

extern init_call init_start;
extern init_call init_end;

void do_initcalls(void);




#endif /*<__INIT_H>*/

