/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:33 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 11日 星期二 08:58:03 CST. */
#include <stdio.h>
#include <tiffio.h>

/**
 *	libtiff
 *	gcc -o tifftest tifftest.c –ltiff
 */

int main (int argc, char** argv)
{
	TIFF* tiff;
	tiff = TIFFOpen (argv[1], "r");
	TIFFClose (tiff);
	return 0;
}
