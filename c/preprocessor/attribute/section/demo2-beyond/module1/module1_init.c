#include <stdio.h>

#define __INIT_LOG
#include "init.h"


int module1_init()
{
	init_log("rongtao1\n");
}
INIT_ADD(module1_init);

