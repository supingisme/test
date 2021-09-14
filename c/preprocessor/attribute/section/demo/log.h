#ifndef __LOG_H
#define __LOG_H 1

#include <stdio.h>

#define log(fmt...) \
	({ \
		int n = 0;\
		n+=fprintf(stdout, "[%s]%s:%d ", __FILE__, __func__, __LINE__);\
		n+=fprintf(stdout, fmt);\
		n;\
	})

#endif /*<__LOG_H>*/
