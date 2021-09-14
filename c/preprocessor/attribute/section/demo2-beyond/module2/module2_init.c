#include <stdio.h>

#define __INIT_LOG
#include "init.h"


int module2_init()
{
	init_log("rongtao1\n");
}

INIT_ADD(module2_init);


