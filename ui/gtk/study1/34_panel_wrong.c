/* 分隔面板 panel.c */
#include <gtk/gtk.h>
int main (int argc, char* argv[])
{
   GtkWidget *window;
   GtkWidget *panel;
   GtkWidget *panel1;
   GtkWidget *button1;
   GtkWidget *button2;
   GtkWidget *button3;

   gtk_init(&argc,&argv);

   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(window),"分隔面板测试程序");
   g_signal_connect(G_OBJECT(window),"destroy",
         G_CALLBACK(gtk_main_quit),NULL);

   panel = gtk_hpanel_new();
   gtk_container_add(GTK_CONTAINER(window),panel);
   gtk_widget_show(panel);

   button1 = gtk_button_new_with_label("按钮一");
   gtk_panel_add1(GTK_PANEL(panel),button1);
   gtk_widget_show(button1);

   panel1 = gtk_vpanel_new();
   gtk_panel_add2(GTK_PANEL(panel),panel1);
   gtk_widget_show(panel1);

   button2 = gtk_button_new_with_label("按钮二");
   gtk_panel_add1(GTK_PANEL(panel1),button2);
   gtk_widget_show(button2);

   button3 = gtk_button_new_with_label("按钮三");
   gtk_panel_add2(GTK_PANEL(panel1),button3);
   gtk_widget_show(button3);


   gtk_widget_show(window);
   gtk_main();
   return FALSE;
}
