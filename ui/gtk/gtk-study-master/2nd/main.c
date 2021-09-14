#include <gtk/gtk.h>
int main( int argc, char *argv[])
{
    GtkWidget *window;
    /*初始化整个GTK+程序，是每一个GTK+程序必不可少的部分*/
    gtk_init(&argc, &argv);
    /*这里生成了一个窗口构件——GtkWindow，GTK_WINDOW_TOPLEVEL包含窗口的标题栏和边框，同意用窗口管理器来进行管理*/
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    /*设置窗口标题*/
    gtk_window_set_title(GTK_WINDOW(window), "一步一步学GTK+ DEMO");
    /*设置窗口默认大小*/
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 400);
    /*
     * 设置窗口在显示器中的位置为居中。
     *   GTK_WIN_POS_NONE            ：不固定
     *   GTK_WIN_POS_CENTER          : 居中
     *   GTK_WIN_POS_MOUSE           : 出现在鼠标位置
     *   GTK_WIN_POS_CENTER_ALWAYS   : 窗口改变大小的时候仍然居中
    */
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    /*开始显示窗口*/
    gtk_widget_show(window);
    gtk_main();
    return 0;
}
