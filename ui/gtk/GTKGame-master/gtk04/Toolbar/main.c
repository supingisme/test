#include <gtk/gtk.h>

int main(int argc,char *argv[])
{
    GtkWidget *window;   /** 窗口 **/
    GtkWidget *vbox;     /** 布局 **/

    GtkWidget *toolbar;  /** 工具栏 **/
    GtkToolItem *f_new;  /** 新建工具选项 **/
    GtkToolItem *open;   /** 打开工具选项 **/
    GtkToolItem *save;   /** 保存工具选项 **/
    GtkToolItem *sep;    /** 分割线 **/
    GtkToolItem *exit;   /** 退出工具选项 **/

    gtk_init(&argc,&argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window),250,200);
    gtk_window_set_title(GTK_WINDOW(window),"toolbar");

    vbox = gtk_vbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(window),vbox);

    toolbar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar),GTK_TOOLBAR_ICONS);
    gtk_container_set_border_width(GTK_CONTAINER(toolbar),2);

    f_new = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar),f_new,-1);

    open = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar),open,-1);

    save = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar),save,-1);

    sep = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar),sep,-1);

    exit = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar),exit,-1);

    gtk_box_pack_start(GTK_BOX(vbox),toolbar,FALSE,FALSE,5);

    g_signal_connect(G_OBJECT(exit),"clicked",G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect_swapped(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}






























