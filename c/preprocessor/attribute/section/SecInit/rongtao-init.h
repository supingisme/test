/**
 *  File:   init.h
 *  Author: Rong Tao
 *  Time:   2020/01/22
 */
#ifndef ___RONGTAO_INIT_FUNC_SECTION_RONG_____H
#define ___RONGTAO_INIT_FUNC_SECTION_RONG_____H 1

#define __SECTION		".rongtao+init-func:section=rong+-:."

typedef int (*section_call_fn)(void);

#define SECTION_FN_ADD(func) \
    section_call_fn __section_fn_##func __attribute__((section(__SECTION))) = func

extern section_call_fn __init_rongtao_init_func_section_rong_____start;
extern section_call_fn __init_rongtao_init_func_section_rong_____end;

#ifdef __SECTION_LOG
#include <stdio.h>
#define SECTION_LOG(fmt...) ({ \
		int n = 0;\
		n+=fprintf(stdout, "["__SECTION"] %s %s:%d ",\
		        __FILE__, __func__, __LINE__);\
		n+=fprintf(stdout, fmt);\
		n;\
	})
#else
#define SECTION_LOG(fmt...)
#endif

#define DO_SECTION_CALLS()  { \
    section_call_fn *__call_fn_ptr = &__init_rongtao_init_func_section_rong_____start; \
    while (__call_fn_ptr && __call_fn_ptr < &__init_rongtao_init_func_section_rong_____end) { \
        SECTION_LOG ("call_ptr: %p\n", __call_fn_ptr); \
        (*__call_fn_ptr)();  \
        ++__call_fn_ptr; \
    };\
}\

#endif /*<___RONGTAO_INIT_FUNC_SECTION_RONG_____H>*/
