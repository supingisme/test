#include <gtk/gtk.h>

//制作应用图标
GdkPixbuf *create_pixbuf(const gchar *filename)
{
    GdkPixbuf *pixbuf;
    GError *error = NULL;

    pixbuf = gdk_pixbuf_new_from_file(filename,&error);

    if(!pixbuf)
    {
        fprintf(stderr,"%s\n",error->message);
        g_error_free(error);
    }

    return pixbuf;
}

int main(int argc,char *argv[])
{
    GtkWidget *window;

    gtk_init(&argc,&argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //设置标题
    gtk_window_set_title(GTK_WINDOW(window),"Center");
    //设置默认大小
    gtk_window_set_default_size(GTK_WINDOW(window),530,150);
    //设置位置
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);

    //设置程序图标
    gtk_window_set_icon(GTK_WINDOW(window),create_pixbuf("icon.png"));
    gtk_widget_show(window);

    //注册关闭事件
    g_signal_connect_swapped(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);

    gtk_main();

    return 0;
}
