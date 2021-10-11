#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <link.h>

//dl_iterate_phdr - walk through list of shared objects
int dl_iterate_phdr(
         int (*callback) (struct dl_phdr_info *info,
                          size_t size, void *data),
         void *data);
