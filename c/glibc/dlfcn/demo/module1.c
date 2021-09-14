
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"
#include "log.h"

void done()
{
	debug();
	printf("Module 1 Done.\n");
}

void init(dll *p)
{
	p->name = (char *)calloc(30, sizeof(char));
	strcpy(p->name, "module1.so init");
	p->done = done;
}
