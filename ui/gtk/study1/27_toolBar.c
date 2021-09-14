/* 添加工具条 toolbar.c*/
#include <gtk/gtk.h>
void on_button_clicked (GtkButton* button,gpointer data)
{
   g_print("你点击的按钮是 %s \n",(gchar*)data);
}
int main (int argc, char* argv[])
{
   GtkWidget* window;
   GtkWidget* box ;
   GtkWidget* toolbar ;
   GtkWidget* entry ;
   GtkWidget* label ;

   gtk_init(&argc,&argv);

   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_widget_set_size_request(window,700,100); 
   gtk_window_set_title(GTK_WINDOW(window),"添加工具条");
   g_signal_connect(G_OBJECT(window),"destroy",
      G_CALLBACK(gtk_main_quit),NULL);

   box = gtk_vbox_new(FALSE,0);
   gtk_container_add(GTK_CONTAINER(window),box);
   toolbar = gtk_toolbar_new();
   gtk_toolbar_insert_stock(GTK_TOOLBAR(toolbar),GTK_STOCK_NEW,
      "新建一个文件","新建",
      GTK_SIGNAL_FUNC(on_button_clicked),
      (gpointer)("新建"),-1);

   gtk_toolbar_insert_stock(GTK_TOOLBAR(toolbar),GTK_STOCK_OPEN,
      "打开一个文件","打开",
      GTK_SIGNAL_FUNC(on_button_clicked),
      (gpointer)("打开"),-1);

   gtk_toolbar_insert_stock(GTK_TOOLBAR(toolbar),GTK_STOCK_SAVE,
      "保存当前文件","保存",
      GTK_SIGNAL_FUNC(on_button_clicked),
      (gpointer)("保存"),-1);

   gtk_toolbar_append_space(GTK_TOOLBAR(toolbar));
   label = gtk_label_new(" 文件名：");
   gtk_toolbar_append_widget(GTK_TOOLBAR(toolbar),label,
      "这是一个标签","标签");
   entry = gtk_entry_new();
   gtk_toolbar_append_widget(GTK_TOOLBAR(toolbar),entry,
      "这是一个录入条","录入");
   gtk_toolbar_append_space(GTK_TOOLBAR(toolbar));
   gtk_toolbar_insert_stock(GTK_TOOLBAR(toolbar),GTK_STOCK_CUT,
      "剪切","剪切",
      GTK_SIGNAL_FUNC(on_button_clicked),
      (gpointer)("剪切"),-1);
   gtk_toolbar_insert_stock(GTK_TOOLBAR(toolbar),GTK_STOCK_COPY,
      "复制","复制",
      GTK_SIGNAL_FUNC(on_button_clicked),
      (gpointer)("复制"),-1);
   gtk_toolbar_insert_stock(GTK_TOOLBAR(toolbar),GTK_STOCK_PASTE,
      "粘贴","粘贴",
      GTK_SIGNAL_FUNC(on_button_clicked),
      (gpointer)("粘贴"),-1);
   gtk_toolbar_append_space(GTK_TOOLBAR(toolbar));
   gtk_toolbar_insert_stock(GTK_TOOLBAR(toolbar),GTK_STOCK_QUIT,
      "退出","退出",
      GTK_SIGNAL_FUNC(on_button_clicked),
      (gpointer)("退出"),-1);
   gtk_toolbar_set_style(GTK_TOOLBAR(toolbar),GTK_TOOLBAR_ICONS);
   gtk_toolbar_set_icon_size(GTK_TOOLBAR(toolbar),
      GTK_ICON_SIZE_SMALL_TOOLBAR);
   gtk_box_pack_start(GTK_BOX(box),toolbar,FALSE,FALSE,0);
   gtk_widget_show_all(window);
   gtk_main();
   return FALSE;
}
