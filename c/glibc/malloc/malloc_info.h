#include <malloc.h>

//malloc_info - export malloc state to a stream
int malloc_info(int options, FILE *fp);
//The  malloc_info()  function exports an XML string that describes the current state of the memory-alloca‐
//tion implementation in the caller.  The string is printed on the file stream  fp.   The  exported  string
//includes information about all arenas (see malloc(3)).

