#include <stdint.h>
#include <stdarg.h>
#include <malloc.h>
#include <string.h>
#include <malloc.h>

struct timer {
	char name[10];
	int id;
};

enum {
	timer_get_name,
	timer_get_id,
	timer_set_name,
	timer_set_id
};

int _ctl(struct timer *timer, int request, ...);


int main()
{
	struct timer t1;

	_ctl(&t1, timer_set_id, 123);
	printf("timer id = %d\n", t1.id);
	int id = 111;
	_ctl(&t1, timer_get_id, &id);
	printf("timer id = %d\n", id);

	_ctl(&t1, timer_set_name, "timerY");
	printf("timer name = %s\n", t1.name);

	char name[10];
	_ctl(&t1, timer_get_name, name);
	printf("timer name = %s\n", name);
	return 0;
}

int _ctl(struct timer *timer, int request, ...)
{
	va_list va;
	va_start(va, request);

	char *_str = NULL;
	long int _id = 0;
	long int *_pid = NULL;

	switch(request)
	{
		case timer_get_name:
			_str = va_arg(va, char*);
			strncpy(_str, timer->name, sizeof(timer->name));
			break;

		case timer_get_id:
			_pid = va_arg(va, long int *);
			*_pid = timer->id;
			break;

		case timer_set_name:
			_str = va_arg(va, char*);
			strncpy(timer->name, _str, sizeof(timer->name));
			break;

		case timer_set_id:
			_id = va_arg(va, int);
			timer->id = (int)_id;
			break;

		default:
			break;
	}

	va_end(va);
}
