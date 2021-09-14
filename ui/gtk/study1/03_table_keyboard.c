#include <gtk/gtk.h>
/* 我们的回调。
* 传到这个函数的数据被打印到标准输出 */
void callback( GtkWidget *widget, gpointer data )
{
    g_print ("%s", (char *) data);
}
/* 这个回调退出程序 */
gint delete_event( GtkWidget *widget, GdkEvent *event, gpointer data )
{
    gtk_main_quit ();
    return FALSE;
}
int main( int argc, char *argv[] )
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *table;
    gtk_init (&argc, &argv);
/* 创建一个新窗口 */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
/* 设置窗口标题 */
    gtk_window_set_title (GTK_WINDOW (window), "Rong Tao's Keyboard");
/* 为 delete_event 设置一个立即退出 GTK 的处理函数。 */
    g_signal_connect (G_OBJECT (window), "delete_event", G_CALLBACK (delete_event), NULL);
/* 设置窗口的边框宽度。 */
    gtk_container_set_border_width (GTK_CONTAINER (window), 20);
/* 创建一个 2x2 的表 */
    table = gtk_table_new (4, 20, TRUE);
/* 将表放进主窗口 */
    gtk_container_add (GTK_CONTAINER (window), table);
/* 创建第一个按钮 */
    button = gtk_button_new_with_label ("Q");
/* 当这个按钮被点击时,我们调用 "callback" 函数,并将一个指向"button 1"的指针作为它的参数 */
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "q");
/* 将 button 1 插入表的左上象限(quadrant) */
    gtk_table_attach_defaults (GTK_TABLE (table), button, 0, 2, 0, 1);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("W");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "w");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 2, 4, 0, 1);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("E");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "e");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 4, 6, 0, 1);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("R");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "r");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 6, 8, 0, 1);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("T");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "t");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 8, 10, 0, 1);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("Y");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "y");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 10, 12, 0, 1);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("U");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "u");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 12, 14, 0, 1);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("I");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "i");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 14, 16, 0, 1);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("O");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "o");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 16, 18, 0, 1);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("P");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "p");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 18, 20, 0, 1);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("A");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "a");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 1, 3, 1, 2);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("S");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "s");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 3, 5, 1, 2);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("D");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "d");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 5, 7, 1, 2);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("F");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "f");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 7, 9, 1, 2);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("G");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "g");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 9, 11, 1, 2);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("H");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "h");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 11, 13, 1, 2);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("J");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "j");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 13, 15, 1, 2);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("K");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "k");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 15, 17, 1, 2);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("L");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "l");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 17, 19, 1, 2);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("'");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "'");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 0, 2, 2, 3);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("Z");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "z");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 2, 4, 2, 3);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("X");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "x");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 4, 6, 2, 3);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("C");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "c");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 6, 8, 2, 3);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("V");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "v");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 8, 10, 2, 3);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("B");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "b");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 10, 12, 2, 3);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("N");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "n");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 12, 14, 2, 3);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("M");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "m");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 14, 16, 2, 3);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label (",");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) ",");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 16, 18, 2, 3);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label (".");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) ".");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 18, 20, 2, 3);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label ("Enter");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) "\n");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 2, 6, 3, 4);
    gtk_widget_show (button);
/*********************/
    button = gtk_button_new_with_label (" ");
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), (gpointer) " ");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 6, 16, 3, 4);
    gtk_widget_show (button);
/* 创建"Quit"按钮 */
    button = gtk_button_new_with_label ("Quit");
/* 当这个按钮被点击时,我们调用 "delete_event" 函数接着程序就退出了 */
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (delete_event), NULL);
/* 将退出按钮插入表的下面两个象限 */
    gtk_table_attach_defaults (GTK_TABLE (table), button, 16, 19, 3, 4);
    gtk_widget_show (button);

    gtk_widget_show (table);
    gtk_widget_show (window);
    gtk_main ();
    return 0;
}
