#include <stdio.h>
#include <stdarg.h>
#include "log.h"

int __log(int level, const char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);

	int len = 0;

	switch(level)
	{
		case __debug:
			len += fprintf(stdout, " [debug]");
			break;

		case __info:
			len += fprintf(stdout, "  [info]");
			break;

		case __error:
			len += fprintf(stdout, " [error]");
			break;

		default:
			break;
	}
	vfprintf(stdout, fmt, va);
	va_end(va);
	fflush(stdout);
	return len;
}
