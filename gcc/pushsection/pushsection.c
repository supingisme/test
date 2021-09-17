#include <stdio.h>
#include <unistd.h>

#if 1
asm(".pushsection .interp,\"a\"\n"
	    "        .ascii \"/usr/bin/ld\\x00\"\n"
	    ".popsection");

    /* .ascii above equals to .string \"/lib/i386-linux-gnu/ld-linux.so.2\"\n */
	#else
	asm(".pushsection .interp,\"a\"\n"
	     "        .incbin \"interp.section.txt\"\n"
	     ".popsection");
	#endif

	int main(void)
	{
		        printf("hello\n");

		        return 0;
	}

	void _start(void)
	{
		printf("my _start.\n");
		        int ret;

		        ret = main();
		        _exit(ret);
	}
