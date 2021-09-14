#include <gtk/gtk.h>
/* 我们新改进的回调函数。传递到该函数的数据将打印到标准输出(stdout)。*/
void callback( GtkWidget *widget, gpointer data )
{
       g_print ("%s ", (gchar *) data);
}
/* 另一个回调函数 */
gint delete_event( GtkWidget *widget, GdkEvent *event, gpointer data )
{
     gtk_main_quit ();
     return FALSE;
}

int main( int argc, char *argv[] )
{
/* GtkWidget 是构件的存储类型 */
      GtkWidget *window;
      GtkWidget *button;
      GtkWidget *box1;

      gtk_init (&argc, &argv);
/* 创建一个新窗口 */
      window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
/* 这是一个新的调用,设置窗口标题为"Hello Buttons!" */
      gtk_window_set_title (GTK_WINDOW (window), "Hello Buttons!");
/* 在这里我们为 delete_event 设置了一个处理函数来立即退出 GTK。*/
      g_signal_connect (G_OBJECT (window), "delete_event",
                        G_CALLBACK (delete_event), NULL);
/* 设置窗口边框的宽度。 */
      gtk_container_set_border_width (GTK_CONTAINER (window), 20);
/* 我们创建了一个组装盒。详情参见“组装”章节。我们看不见组装盒,它仅被作为排列构件的工具。*/
      box1 = gtk_hbox_new (FALSE, 1);
/* 把组装盒放入主窗口中。*/
      gtk_container_add (GTK_CONTAINER (window), box1);
/* 创建一个标签为 "Button 1" 的新按钮。*/
      button = gtk_button_new_with_label ("Hello");
/* 当按钮被按下时,我们调用 "callback" 函数,并将一个指向 "button 1" 的指针作为它的参数。*/
      g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), "hello");
/* 代替 gtk_container_add,我们把按钮放入不可见的组装盒,该组合盒已经组装进窗口中了。*/
      gtk_box_pack_start (GTK_BOX(box1), button, TRUE, TRUE, 0);
/* 总是记住这一步,它告诉 GTK 我们为这个按钮做的准备工作已经完成了,现在可以显示它了。*/
      gtk_widget_show (button);
/* 同样创建第二个按钮。*/
      button = gtk_button_new_with_label ("World");
      g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), "World");
      gtk_box_pack_start(GTK_BOX (box1), button, TRUE, TRUE, 0);
      gtk_widget_show (button);
/* 同样创建第3个按钮。*/
      button = gtk_button_new_with_label ("!");
      g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), "!");
      gtk_box_pack_start(GTK_BOX (box1), button, TRUE, TRUE, 0);
      gtk_widget_show (button);

      gtk_widget_show (box1);
      gtk_widget_show (window);
/* 停在这里等待事件发生。*/
      gtk_main ();
      return 0;
}

