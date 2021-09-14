/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:52 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:52 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:36 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:09 CST. */
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

/* LPROP: $Revision: 1.6 $ ; $Date: 2011/11/21 17:03:15 $	*/

/*********************** self documentation **********************/
/*
 * LPROP - List PROPerties of root window of default screen of display 
 *
 * Usage:  lprop
 *
 */
/**************** end self doc ********************************/

#include "par.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>

char *sdoc[] = {
" 									",
" 									",
NULL};

int
main(int argc, char **argv)
{
	Display *dpy;
	Atom *atom;
	int i,natoms;

	/* connect to X server */
	if ((dpy=XOpenDisplay(NULL))==NULL) {
		fprintf(stderr,"Cannot connect to display %s\n",
			XDisplayName(NULL));
		exit(-1);
	}

	/* list properties of root window */
	atom = XListProperties(dpy,DefaultRootWindow(dpy),&natoms);
	printf("Number of properties = %d\n",natoms);
	for (i=0; i<natoms; i++)
		printf("property[%d] = %s\n",i,XGetAtomName(dpy,atom[i]));

	/* close connection to X server */
	XCloseDisplay(dpy);

	return EXIT_SUCCESS;
}
