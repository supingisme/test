/* 状态栏 status.c */
#include <gtk/gtk.h>
static GtkWidget *statusbar;
gint i = 0 ;
void on_push_clicked (GtkButton* button,gpointer data)
{
   char message[1024];
   i++ ;
   sprintf(message,"这是输入的第 %d 条消息．",i);
   gtk_statusbar_push(GTK_STATUSBAR(statusbar),i,message);
}
void on_pop_clicked (GtkButton* button,gpointer data)
{
   if (i<0) return ;
   gtk_statusbar_pop(GTK_STATUSBAR(statusbar),i);
   i--;
}
void on_popped (GtkStatusbar* statusbar,guint id,const gchar*
text)
{
   if(!statusbar->messages)
   i = 0;
}
int main ( int argc , char* argv[])
{
   GtkWidget *window;
   GtkWidget *vbox,*hbox;
   GtkWidget *button;

   gtk_init(&argc,&argv);

   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   g_signal_connect(G_OBJECT(window),"delete_event",
      G_CALLBACK(gtk_main_quit),NULL);
   gtk_window_set_title(GTK_WINDOW(window),"状态栏");
  // gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
   gtk_container_set_border_width(GTK_CONTAINER(window),20);

   vbox = gtk_vbox_new(FALSE,0);
   gtk_container_add(GTK_CONTAINER(window),vbox);

   statusbar = gtk_statusbar_new();
   g_signal_connect(G_OBJECT(statusbar),"text-popped",
      G_CALLBACK(on_popped),NULL);

   gtk_box_pack_start(GTK_BOX(vbox),statusbar,FALSE,FALSE,5);

   hbox = gtk_hbox_new(FALSE,0);
   gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE,5);

   button = gtk_button_new_with_label("推入");
   g_signal_connect(G_OBJECT(button),"clicked",
      G_CALLBACK(on_push_clicked),NULL);

   gtk_box_pack_start(GTK_BOX(hbox),button,TRUE,TRUE,5);
   button = gtk_button_new_with_label("弹出");
   g_signal_connect(G_OBJECT(button),"clicked",
      G_CALLBACK(on_pop_clicked),NULL);

   gtk_box_pack_start(GTK_BOX(hbox),button,TRUE,TRUE,5);
   gtk_widget_show_all(window);
   gtk_main();
   return FALSE;
}

