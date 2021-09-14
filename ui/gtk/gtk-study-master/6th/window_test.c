#include "window_test.h"
//
extern GtkWidget *window_test;
extern GtkWidget *label;

static gint delete_event()
{
    /* 如果你的 "delete_event" 信号处理函数返回 FALSE，GTK 会发出 "destroy" 信号。
    * 返回 TRUE，你不希望关闭窗口。
    * 当你想弹出“你确定要退出吗?”对话框时它很有用。*/
    gtk_widget_hide_all(window_test);

    return TRUE; //注意必须为TRUE，否则子窗口点击关闭按钮后，就摧毁了，而不是隐藏了。
}


static void change_label_text()
{
    char *text="我是子窗口的动作改变的";
    gtk_label_set_text(GTK_LABEL(label),text);
}



 GtkWidget *create_test_window()
 { //创建一个测试窗口

    GtkWidget *window_test;
    GtkWidget *fixed;
    GtkWidget *button;

    window_test = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window_test), 300, 200);
    fixed = gtk_fixed_new();

    button=gtk_button_new_with_label("改变主窗口label文字");
    gtk_fixed_put(GTK_FIXED(fixed), button, 50, 50);
    gtk_widget_set_size_request(button, 80, 65);

    gtk_container_add(GTK_CONTAINER(window_test), fixed);

    //gtk_widget_show(window);
    g_signal_connect(G_OBJECT(window_test),"delete_event",G_CALLBACK(delete_event), NULL); //注意这里不是“destroy” 事件
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_label_text), NULL);

    //gtk_main();
    //return 0;
    return window_test;
 }
