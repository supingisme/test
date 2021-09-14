#include <stdio.h>
#include <stdarg.h>

int __print__(FILE *fp, char *file, char *func, int line, const char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	vfprintf(fp, fmt, va);
	va_end(va);
}
