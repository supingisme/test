#include <gtk/gtk.h>
#include "common_func.h"
#include "window_main.h"
#include "window_test.h"

//Global
GtkWidget *window_test = NULL;  //子窗口本身
GtkWidget *label = NULL;        //主窗口中的label


int main( int argc, char *argv[])
{
    GtkWidget *window_main;     //主窗口不会在子窗口中使用，故不用声明为全局变量

    gtk_init(&argc, &argv);

    window_main=create_main_window(); //创建主窗口
    window_test=create_test_window(); //创建测试窗口

    gtk_widget_show_all(window_main); //显示主窗口
    //gtk_widget_show_all(window_test); //显示测试窗口


    gtk_main();
    return 0;

}
