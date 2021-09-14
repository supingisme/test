#ifndef __DLL_H
#define __DLL_H

typedef struct dll{
	char * name;
	int (*init)();
	void (*done)();
}dll;


#endif //__DLL_H
