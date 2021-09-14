#include <setjmp.h>

void longjmp(jmp_buf env, int val);

void siglongjmp(sigjmp_buf env, int val);

