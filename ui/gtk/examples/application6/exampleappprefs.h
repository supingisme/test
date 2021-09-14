/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:48 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:13 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:24 CST. */
#ifndef __EXAMPLEAPPPREFS_H
#define __EXAMPLEAPPPREFS_H

#include <gtk/gtk.h>
#include "exampleappwin.h"


#define EXAMPLE_APP_PREFS_TYPE (example_app_prefs_get_type ())
G_DECLARE_FINAL_TYPE (ExampleAppPrefs, example_app_prefs, EXAMPLE, APP_PREFS, GtkDialog)


ExampleAppPrefs        *example_app_prefs_new          (ExampleAppWindow *win);


#endif /* __EXAMPLEAPPPREFS_H */
