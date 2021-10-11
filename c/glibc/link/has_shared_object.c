#define _GNU_SOURCE
#include <link.h>
#include <libgen.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int check_so_cb(struct dl_phdr_info *info, size_t size, void *data)
{
	const char *soname = data;
	int so_used = 0;

	if (!strncmp(basename(info->dlpi_name), soname, strlen(soname)))
		so_used = 1;

	return so_used;
}

/* check whether the given library name is in shared object list */
static int has_shared_object(const char *soname)
{
	static int so_used = -1;

	if (so_used != -1)
		return so_used;

	so_used = dl_iterate_phdr(check_so_cb, (void*)soname);

	return so_used;
}

int main()
{
	char *lib = "linux-vdso.so.1";

	if(has_shared_object(lib)) {
		printf("has_shared_object %s.\n", lib);
	}
}
