#ifndef __log_h
#define __log_h

enum {
	__debug,
	__info,
	__error,
};

#define debug(fmt...) __log(__debug, fmt)
#define info(fmt...) __log(__info, fmt)
#define error(fmt...) __log(__error, fmt)


int __log(int level, const char *fmt, ...);


#endif
