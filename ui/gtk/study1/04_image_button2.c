/* 带图像的按钮 button.c */
#include <gtk/gtk.h>
void on_button_clicked (GtkWidget* button,gpointer data)
{
   //g_print("按钮 %s ",(gchar*)data);
   g_print("Button %s is pressed.\n",(gchar*)data);
   //g_print("被按了一下． \n");
}
//创建自己按钮的函数
GtkWidget* create_button1 (void)
{
   GtkWidget* box;
   GtkWidget* image;
   GtkWidget* label;
   GtkWidget* button;
   char* title = "文件家";
   image = gtk_image_new_from_file("dir2.jpg");
   label = gtk_label_new(title);
   box = gtk_vbox_new(FALSE,2);
   gtk_container_set_border_width(GTK_CONTAINER(box),5);
   gtk_box_pack_start(GTK_BOX(box),image,FALSE,FALSE,3);
   gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,3);
   gtk_widget_show(image);
   gtk_widget_show(label);
   button = gtk_button_new();
   gtk_container_add(GTK_CONTAINER(button),box);
   gtk_widget_show(box);
   return button ;
}
GtkWidget* create_button2 (void)
{
   GtkWidget* box;
   GtkWidget* image;
   GtkWidget* label;
   GtkWidget* button;
   char* title = "蝙蝠侠";
   image = gtk_image_new_from_file("batman.jpg");
   label = gtk_label_new(title);
   box = gtk_hbox_new(FALSE,2);
   gtk_container_set_border_width(GTK_CONTAINER(box),5);
   gtk_box_pack_start(GTK_BOX(box),image,FALSE,FALSE,3);
   gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,3);
   gtk_widget_show(image);
   gtk_widget_show(label);
   button = gtk_button_new();
   gtk_container_add(GTK_CONTAINER(button),box);
   gtk_widget_show(box);
   return button ;
}
//主函数
int main (int argc, char *argv[])
{
   GtkWidget* window;
   GtkWidget* box;
   GtkWidget* button1;
   GtkWidget* button2;
   GtkWidget* button3;
   GtkWidget* button4;

   gchar* title = "带图像和快捷键的按钮";
   gchar* b1 = "Red apple";//"红苹果"
   gchar* b2 = "Small mushroom";//"小蘑菇"
   gchar* b3 = "Short key";//"快捷键"
   gchar* b4 = "OK";//"确认"
   gtk_init(&argc,&argv);
   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(window),title);
   gtk_container_set_border_width(GTK_CONTAINER(window),20);
   g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
   box = gtk_hbox_new(FALSE,0);
   gtk_container_add(GTK_CONTAINER(window),box);
   button1 = create_button1();
   g_signal_connect(G_OBJECT(button1),"clicked",
   G_CALLBACK(on_button_clicked),(gpointer)b1);
   gtk_box_pack_start(GTK_BOX(box),button1,FALSE,FALSE,5);
   button2 = create_button2();
   g_signal_connect(G_OBJECT(button2),"clicked",
   G_CALLBACK(on_button_clicked),(gpointer)b2);
   gtk_box_pack_start(GTK_BOX(box),button2,FALSE,FALSE,5);
   button3 = gtk_button_new_with_mnemonic("快捷键(_H)");
   g_signal_connect(G_OBJECT(button3),"clicked",
   G_CALLBACK(on_button_clicked),(gpointer)b3);
   gtk_box_pack_start(GTK_BOX(box),button3,FALSE,FALSE,5);
   button4 = gtk_button_new_from_stock(GTK_STOCK_OK);
   g_signal_connect(G_OBJECT(button4),"clicked",
   G_CALLBACK(on_button_clicked),(gpointer)b4);
   gtk_box_pack_start(GTK_BOX(box),button4,FALSE,FALSE,5);
   gtk_widget_show_all(window);
   gtk_main();
   return FALSE ;
}
