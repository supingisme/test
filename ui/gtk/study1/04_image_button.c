#include <stdlib.h>
#include <gtk/gtk.h>
/* 创建一个新的横向盒,它包含一个图像和一个标签,并返回这个盒。*/
GtkWidget *xpm_label_box( gchar *xpm_filename, gchar *label_text )
{
   GtkWidget *box;
   GtkWidget *label;
   GtkWidget *image;
/* 为图像和标签创建盒 */
   box = gtk_hbox_new (FALSE, 0);
   gtk_container_set_border_width (GTK_CONTAINER (box), 10);
/* 创建一个图像 */
   image = gtk_image_new_from_file (xpm_filename);
/* 为按钮创建一个标签 */
   label = gtk_label_new (label_text);
/* 把图像和标签组装到盒子里 */
   gtk_box_pack_start (GTK_BOX (box), image, TRUE, TRUE, 3);
   gtk_box_pack_start (GTK_BOX (box), label, TRUE, TRUE, 3);
   gtk_widget_show (image);
   gtk_widget_show (label);
   return box;
}
/* 我们常见的回调函数 */
void callback( GtkWidget *widget, gpointer data )
{
   g_print ("Hello again - %s was pressed\n", (char *) data);
}
int main( int argc, char *argv[] )
{
/* GtkWidget 是构件的存储类型 */
   GtkWidget *window;
   GtkWidget *button;
   GtkWidget *box;
   gtk_init (&argc, &argv);
/* 创建一个新窗口 */
   window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title (GTK_WINDOW (window), "RT's Image");
/* 对所有的窗口做这一步是一个好主意。*/
   g_signal_connect (G_OBJECT (window), "destroy", 
                     G_CALLBACK (gtk_main_quit), NULL);
   g_signal_connect (G_OBJECT (window), "delete_event", 
                     G_CALLBACK (gtk_main_quit), NULL);
/* 设置窗口边框的宽度。*/
   gtk_container_set_border_width (GTK_CONTAINER (window), 10);
/* 创建一个新的按钮 */
   button = gtk_button_new ();
/* 连接按钮的 "clicked" 信号到我们的回调 */
   g_signal_connect (G_OBJECT (button), "clicked", 
                     G_CALLBACK (callback), (gpointer) "button");
/* 调用我们的创建盒的函数 */
   box = xpm_label_box ("pic/batman.jpg", "蝙蝠侠桌面");
/* 组装和显示所有的构件 */
   gtk_widget_show (box);
   gtk_container_add (GTK_CONTAINER (button), box);
   gtk_widget_show (button);
   gtk_container_add (GTK_CONTAINER (window), button);
   gtk_widget_show (window);
/* 停在这里,等待事件发生。 */
   gtk_main ();
   return 0;
}

