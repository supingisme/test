/* 图像的直接引用 pixmap.c */
#include <gtk/gtk.h>
#include "a.h" //这里买年包含了一个pixmap图像
int main ( int argc , char* argv[])
{
   GtkWidget *window;
   GtkWidget *vbox;
   GtkWidget *frame;
   GtkWidget *image;
   GdkPixbuf *pixbuf;
   GdkPixbuf *pix1,*pix2,*pix3;

   gtk_init(&argc,&argv);

   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   g_signal_connect(G_OBJECT(window),"delete_event",
      G_CALLBACK(gtk_main_quit),NULL);
   gtk_window_set_title(GTK_WINDOW(window),"图像的直接引用");
   gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
   gtk_container_set_border_width(GTK_CONTAINER(window),10);

   vbox = gtk_vbox_new(FALSE,0);
   gtk_container_add(GTK_CONTAINER(window),vbox);

   pixbuf = gdk_pixbuf_new_from_file("b.png",NULL);
   frame = gtk_frame_new("这是一幅完整的图像");
   image = gtk_image_new_from_pixbuf(pixbuf);
   gtk_box_pack_start(GTK_BOX(vbox),frame,FALSE,FALSE,5);
   gtk_container_add(GTK_CONTAINER(frame),image);

   pix1 = gdk_pixbuf_new_subpixbuf(pixbuf,280,40,40,40);
   frame = gtk_frame_new("从上图中分割出来的一幅图像");
   image = gtk_image_new_from_pixbuf(pix1);
   gtk_container_add(GTK_CONTAINER(frame),image);
   gtk_box_pack_start(GTK_BOX(vbox),frame,FALSE,FALSE,5);

   pix2 =gdk_pixbuf_new_from_inline(22400+24,pieces_inline,TRUE,NULL);
   frame = gtk_frame_new("内建的一幅图像");
   image = gtk_image_new_from_pixbuf(pix2);
   gtk_container_add(GTK_CONTAINER(frame),image);
   gtk_box_pack_start(GTK_BOX(vbox),frame,FALSE,FALSE,5);
   pix3 = gdk_pixbuf_new_subpixbuf(pix2,120,20,20,20);
   frame = gtk_frame_new("从内建图像中分割出来的一幅图像");
   image = gtk_image_new_from_pixbuf(pix3);
   gtk_container_add(GTK_CONTAINER(frame),image);
   gtk_box_pack_start(GTK_BOX(vbox),frame,FALSE,FALSE,5);
   gtk_widget_show_all(window);
   gtk_main();
   return FALSE;
}
