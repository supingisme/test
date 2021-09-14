#include "window_test.h"

 GtkWidget *create_test_window()
 { //创建一个测试窗口


    GtkWidget *window_test;

    window_test = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_show(window_test);
    //gtk_main();
    //return 0;
    return window_test;
 }
