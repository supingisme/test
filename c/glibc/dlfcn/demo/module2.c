#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"
#include "log.h"

void done()
{
	debug();
	printf("Module 2 Done.\n");
}

void init(dll *p)
{
	p->name = (char *)calloc(33, sizeof(char));
	strcpy(p->name, "module2.so");
	p->done = done;
}
