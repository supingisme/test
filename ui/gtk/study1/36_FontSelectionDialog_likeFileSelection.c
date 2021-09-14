/* 选择字体 fontsel.c */
#include <gtk/gtk.h>
void on_font_select_ok (GtkWidget *button,GtkFontSelectionDialog *fs)
{
   GtkWidget *dialog;
   gchar message[1024];
   gchar *s = gtk_font_selection_dialog_get_font_name(fs);
   sprintf(message,"你选择的字体是：%s \n",s);
   dialog = gtk_message_dialog_new(NULL,
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_INFO,
            GTK_BUTTONS_OK,
            message,
            NULL);
   g_free(s);
   gtk_widget_destroy(GTK_WIDGET(fs));
   gtk_dialog_run(GTK_DIALOG(dialog));
   gtk_widget_destroy(dialog);
}
void on_button_clicked (GtkWidget *button,gpointer userdata)
{
   GtkWidget* dialog ;

   dialog = gtk_font_selection_dialog_new("请选择一种字体：");
   gtk_window_set_position(GTK_WINDOW(dialog),GTK_WIN_POS_CENTER);
   gtk_signal_connect(GTK_OBJECT(dialog),"destroy",
         GTK_SIGNAL_FUNC(gtk_widget_destroy),&dialog);
   gtk_signal_connect(GTK_OBJECT(GTK_FONT_SELECTION_DIALOG(dialog)->ok_button),
         "clicked",GTK_SIGNAL_FUNC(on_font_select_ok),
         GTK_FONT_SELECTION_DIALOG(dialog));

   gtk_signal_connect_object(GTK_OBJECT(GTK_FONT_SELECTION_DIALOG(dialog)->cancel_button),
         "clicked",GTK_SIGNAL_FUNC(gtk_widget_destroy),
         GTK_OBJECT(dialog));

   gtk_widget_show(dialog);
}
int main ( int argc , char* argv[])
{
   GtkWidget *window;
   GtkWidget *button;

   gtk_init(&argc,&argv);

   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   g_signal_connect(G_OBJECT(window),"delete_event",
         G_CALLBACK(gtk_main_quit),NULL);
   gtk_window_set_title(GTK_WINDOW(window),"字体选择功能实现");
   gtk_window_set_default_size(GTK_WINDOW(window),500,100);
   //gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
   gtk_container_set_border_width(GTK_CONTAINER(window),40);

   button = gtk_button_new_with_label("按下此按钮来选择字体");
   g_signal_connect(G_OBJECT(button),"clicked",
         G_CALLBACK(on_button_clicked),NULL);
   gtk_container_add(GTK_CONTAINER(window),button);
   gtk_widget_show(button);


   gtk_widget_show(window);
   gtk_main();
   return FALSE;
}
