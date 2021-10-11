#ifdef HAVE_LIBELF
#include "symbol-libelf.h"
#else
#include "symbol-rawelf.h"
#endif

#include <malloc.h>
#define TEST_NG (-1)
#define TEST_OK 1
#define TEST_EQ(a, b) \
	if(!(a == b)) {	\
		printf("EQ:\n");	\
	}	

int rawelf_validate()
{
	struct uftrace_elf_data elf;
	struct uftrace_elf_iter iter;
	Elf_Ehdr *ehdr;
	unsigned int count;

	/* elf_init() calls elf_validate() internally */
	if (elf_init("/proc/self/exe", &elf) < 0)
		return TEST_NG;

	ehdr = &elf.ehdr;

	count = 0;
	elf_for_each_phdr(&elf, &iter)
		count++;
	TEST_EQ(ehdr->e_phnum, count);

	count = 0;
	elf_for_each_shdr(&elf, &iter)
		count++;
	TEST_EQ(ehdr->e_shnum, count);

	elf_finish(&elf);
	return TEST_OK;
}

char * get_soname(const char *filename)
{
	struct uftrace_elf_data elf;
	struct uftrace_elf_iter iter;
	char *soname = NULL;

	if (elf_init(filename, &elf) < 0) {
		printf("error during open symbol file: %s: %m\n", filename);
		return NULL;
	}

	elf_for_each_shdr(&elf, &iter) {
		if (iter.shdr.sh_type == SHT_DYNAMIC)
			break;
	}

	elf_for_each_dynamic(&elf, &iter) {
		if (iter.dyn.d_tag != DT_SONAME)
			continue;

		soname = strdup(elf_get_name(&elf, &iter, iter.dyn.d_un.d_ptr));
		break;
	}

	elf_finish(&elf);
	return soname;
}

int main()
{
	rawelf_validate();
}
