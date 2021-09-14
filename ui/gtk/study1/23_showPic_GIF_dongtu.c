/* 简单的动画 gif.c */
#include <gtk/gtk.h>
static GtkWidget *ourgif ;
static gchar *bmpfile[4] = {"l.bmp","r.bmp","u.bmp","d.bmp" };
gint i = 0 ;
void change_bmp ()
{ //依次更改图像实现动态效果
   gtk_image_set_from_file(GTK_IMAGE(ourgif),bmpfile[i]);
   i++ ;
   if ( i == 4 ) i = 0 ;
}
int main ( int argc , char* argv[])
{
   GtkWidget *window;
   GtkWidget *vbox;
   GtkWidget *hbox;
   GtkWidget *label;
   GtkWidget *image;

   gtk_init(&argc,&argv);

   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   g_signal_connect(G_OBJECT(window),"delete_event",
         G_CALLBACK(gtk_main_quit),NULL);
   gtk_window_set_title(GTK_WINDOW(window),"简单的动画");
   //gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
   gtk_container_set_border_width(GTK_CONTAINER(window),10);

   vbox = gtk_vbox_new(FALSE,0);
   gtk_container_add(GTK_CONTAINER(window),vbox);

   label = gtk_label_new("直接引用GIF动画");
   gtk_box_pack_start(GTK_BOX(vbox),label,FALSE,FALSE,5);
   image = gtk_image_new_from_file("a.gif");
   gtk_box_pack_start(GTK_BOX(vbox),image,FALSE,FALSE,5);

   label = gtk_label_new("四幅静态的图像");
   gtk_box_pack_start(GTK_BOX(vbox),label,FALSE,FALSE,5);

   hbox = gtk_hbox_new(FALSE,0);
   gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE,5);

   image = gtk_image_new_from_file("l.bmp");
   gtk_box_pack_start(GTK_BOX(hbox),image,FALSE,FALSE,5);
   image = gtk_image_new_from_file("r.bmp");
   gtk_box_pack_start(GTK_BOX(hbox),image,FALSE,FALSE,5);
   image = gtk_image_new_from_file("u.bmp");
   gtk_box_pack_start(GTK_BOX(hbox),image,FALSE,FALSE,5);
   image = gtk_image_new_from_file("d.bmp");
   gtk_box_pack_start(GTK_BOX(hbox),image,FALSE,FALSE,5);

   label = gtk_label_new("通过时钟控制的动画");
   gtk_box_pack_start(GTK_BOX(vbox),label,FALSE,FALSE,5);

   ourgif = gtk_image_new_from_file("p1.bmp");
   gtk_box_pack_start(GTK_BOX(vbox),ourgif,FALSE,FALSE,5);

   gtk_timeout_add(150,(GtkFunction)change_bmp,NULL);


   gtk_widget_show_all(window);
   gtk_main();
   return FALSE;
}
