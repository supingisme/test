#ifndef __LOG_H
#define __LOG_H 1

#define _DEBUG 1
#ifndef debug
#define debug() printf("[debug][%s:%d]\n", __func__, __LINE__)
#else
#define debug()
#endif


#endif //__LOG_H
