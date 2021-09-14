#include <gtk/gtk.h>
#include "common_func.h"
#include "window_main.h"
#include "window_test.h"

int main( int argc, char *argv[])
{
    GtkWidget *main_window ,*test_window;
    gtk_init(&argc, &argv);

    main_window=create_test_window(); //创建主窗口
    test_window=create_main_window(); //创建测试窗口

    gtk_widget_show_all(main_window); //显示主窗口
    gtk_widget_show_all(test_window); //显示测试窗口
    gtk_main();
    return 0;

}
