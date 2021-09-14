/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:50 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:51 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:34 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:08 CST. */
#include <stdio.h>
#include <stdlib.h>

#define nxfor(i) for(i=0;i<nx;i++)
#define nzfor(i) for(i=0;i<nz;i++)

int main(int argc, char *argv[])
{
	int ix, iz, nx, nz;

	float val = .0f;

	nx = 100;
	nz = 100;

	FILE *fp = fopen("vel.dat", "wb");

	nxfor(ix)
		nzfor(iz)
		{
			val = ix + iz;
			fwrite(&val, 1, sizeof(float), fp);
		}
	fclose(fp);
}
