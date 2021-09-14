#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <stdio.h>

typedef struct {
   cookie_read_function_t  *read;
   cookie_write_function_t *write;
   cookie_seek_function_t  *seek;
   cookie_close_function_t *close;
} cookie_io_functions_t;


//fopencookie - opening a custom stream
//从流中打开内存
FILE *fopencookie(void *cookie, const char *mode,
                 cookie_io_functions_t io_funcs);

