#include <stdlib.h>

//malloc_get_state, malloc_set_state - record and restore state of malloc implementation
void* malloc_get_state(void);
//On success, malloc_get_state() returns a pointer to a newly allocated opaque data  structure.   
//On  error returns NULL.

//int malloc_set_state(void *state);
//On  success,  malloc_set_state() returns 0. 

