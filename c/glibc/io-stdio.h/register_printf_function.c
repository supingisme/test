/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:13 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:24 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:55 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:32 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:09 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:48 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <printf.h>
typedef struct
{
	char *name;
}
Widget;
int
print_widget (FILE *stream,
		const struct printf_info *info,
		const void *const *args)
{
	const Widget *w;
	char *buffer;
	int len;
	/* Format the output into a string. */
	w = *((const Widget **) (args[0]));
	len = asprintf (&buffer, "<Widget %p: %s>", w, w->name);
	if (len == -1)
		return -1;
	/* Pad to the minimum feld width and print to the stream. */
	len = fprintf (stream, "%*s",
			(info->left ? -info->width : info->width),
			buffer);
	/* Clean up and return. */
	free (buffer);
	return len;
}
int
print_widget_arginfo (const struct printf_info *info, size_t n,
		int *argtypes)
{
	/* We always take exactly one argument and this is a pointer to the
	 * structure.. */
	if (n > 0)
		argtypes[0] = PA_POINTER;
	return 1;
}
int
main (void)
{
	/* Make a widget to print. */
	Widget mywidget;
	mywidget.name = "mywidget";
	/* Register the print function for widgets. */
	register_printf_function ('W', print_widget, print_widget_arginfo);
	/* Now print the widget. */
	printf ("|%W|\n", &mywidget);
	printf ("|%35W|\n", &mywidget);
	printf ("|%-35W|\n", &mywidget);
	return 0;
}
