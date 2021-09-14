/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:48 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:49 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:33 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:07 CST. */
#include <stdio.h>
#include <string.h>
#include <malloc.h>


const char *sdoc[] = {
"This is a test self document",
"Write by rongtao at 2018.12.29",
"n1: ",
"f1: ",
"d1: ",
NULL
};

int main(int argc, char *argv[])
{
	/* initialize getpar */
	initargs(argc,argv);
	requestdoc(1);

    int n1;
    float f1, d1;
    
    /* get parameters describing 1st dimension sampling */
    if (!getparint("n1",&n1))
        err("Must specify number of samples in 1st dimension!\n");

    d1 = 1.0;  getparfloat("d1",&d1);
    f1 = 0.0;  getparfloat("f1",&f1);
	char *filename = malloc(256);
	memset(filename, 0, 256);
	if(!getparstring("file", &filename))
	{
		err("Must define file\n");
	}

    printf("n1 = %d, f1 = %f, d1 = %f, file = %s\n", n1, f1, d1, filename);
    

	//if(filename!=NULL)free(filename);

	return 0;
}
