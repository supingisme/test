// A app //
///////////////////////////////////////////////////////////////////////////////////////////////////a
///////////////////////////////////////////////////////////////////////////////////////////////////a
///////////////////////////////////////////////////////////////////////////////////////////////////a
///////////////////////////////////////////////////////////////////////////////////////////////////a
/*a 回调函数文件 callbacks.c */
#include <gtk/gtk.h>
gboolean on_window_delete_event (GtkWidget* widget,
GdkEvent *event,
gpointer data)
{
   gtk_main_quit();
   return FALSE;
}
void on_file_new_activate (GtkMenuItem* menuitem, gpointer data)
{
   g_print("the file_new is clicked .\n");
}
void on_file_open_activate (GtkMenuItem* menuitem, gpointer data)
{
}
void on_file_save_activate (GtkMenuItem* menuitem, gpointer data)
{
}
void on_file_saveas_activate (GtkMenuItem* menuitem, gpointer data)
{
}
void on_file_exit_activate (GtkMenuItem* menuitem,gpointer data)
{
}
void on_edit_cut_activate (GtkMenuItem* menuitem,gpointer data)
{
}
void on_edit_copy_activate (GtkMenuItem* menuitem,gpointer data)
{
}
void on_edit_paste_activate (GtkMenuItem* menuitem,gpointer data)
{
}
void on_edit_selectall_activate (GtkMenuItem* menuitem,gpointer data)
{
}
void on_edit_find_activate (GtkMenuItem* menuitem,gpointer data)
{
}
void on_help_help_activate (GtkMenuItem* menuitem,gpointer data)
{
}
void on_help_about_activate (GtkMenuItem* menuitem,gpointer data)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////a
///////////////////////////////////////////////////////////////////////////////////////////////////a
///////////////////////////////////////////////////////////////////////////////////////////////////a
///////////////////////////////////////////////////////////////////////////////////////////////////a
/* 界面代码文件 interface.c */
//#include <gtk/gtk.h>
//#include "callbacks.h"
GtkWidget* create_menu (GtkAccelGroup* accel_group,GtkWidget *window);
GtkWidget* create_toolbar (GtkWidget* window);
GtkWidget* create_window (void)
{
   GtkWidget* window;
   GtkWidget* text;
   GtkWidget* scrolledwin;
   GtkWidget* box;
   GtkWidget* statusbar;
   GtkWidget* menubar ;
   GtkWidget* toolbar ;
   GtkAccelGroup* accel_group ;
   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(window),"完整的应用程序窗口");
   gtk_window_set_default_size(GTK_WINDOW(window),400,300);
   accel_group = gtk_accel_group_new();
   gtk_window_add_accel_group(GTK_WINDOW(window),accel_group);
   box = gtk_vbox_new(FALSE,0);
   gtk_container_add (GTK_CONTAINER (window), box);
   menubar = create_menu(accel_group,window);
   gtk_box_pack_start(GTK_BOX(box),menubar,0,0,0);
   toolbar = create_toolbar(window);
   gtk_box_pack_start(GTK_BOX(box),toolbar,0,1,0);
   scrolledwin = gtk_scrolled_window_new(NULL,NULL);
   text = gtk_text_view_new();
   gtk_box_pack_start(GTK_BOX(box),scrolledwin,TRUE,TRUE,0);
   gtk_container_add(GTK_CONTAINER(scrolledwin),text);
   gtk_text_view_set_editable(GTK_TEXT_VIEW(text),TRUE);
   statusbar = gtk_statusbar_new();
   gtk_box_pack_start(GTK_BOX(box),statusbar,FALSE,FALSE,0);
   gtk_widget_show_all(window);
   return window;
}
GtkWidget* create_menu (GtkAccelGroup* accel_group,GtkWidget *window)
{
   GtkWidget* menubar;
   GtkWidget* menu;
   GtkWidget* editmenu;
   GtkWidget* helpmenu;
   GtkWidget* rootmenu;
   GtkWidget* menuitem;
   menu = gtk_menu_new();//文件菜单
   menuitem = gtk_image_menu_item_new_from_stock
      (GTK_STOCK_NEW,accel_group);
   gtk_menu_shell_append(GTK_MENU_SHELL(menu),menuitem);
   g_signal_connect(G_OBJECT(menuitem),"activate",
      G_CALLBACK(on_file_new_activate),NULL);
   menuitem = gtk_image_menu_item_new_from_stock
      (GTK_STOCK_OPEN,accel_group);
   gtk_menu_shell_append(GTK_MENU_SHELL(menu),menuitem);
   g_signal_connect(G_OBJECT(menuitem),"activate",
      G_CALLBACK(on_file_new_activate),NULL);
   menuitem = gtk_image_menu_item_new_from_stock
      (GTK_STOCK_SAVE,accel_group);
   gtk_menu_shell_append(GTK_MENU_SHELL(menu),menuitem);
   menuitem = gtk_image_menu_item_new_from_stock
      (GTK_STOCK_SAVE_AS,accel_group);
   gtk_menu_shell_append(GTK_MENU_SHELL(menu),menuitem);
   menuitem = gtk_separator_menu_item_new();
   gtk_menu_shell_append(GTK_MENU_SHELL(menu),menuitem);
   menuitem = gtk_image_menu_item_new_from_stock
      (GTK_STOCK_QUIT,accel_group);
   gtk_menu_shell_append(GTK_MENU_SHELL(menu),menuitem);
   g_signal_connect(G_OBJECT(menuitem),"activate",
      G_CALLBACK(on_window_delete_event),NULL);
   rootmenu = gtk_menu_item_new_with_label(" 文件 ");
   gtk_widget_show(rootmenu);
   gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu),menu);
   menubar = gtk_menu_bar_new();
   gtk_menu_shell_append(GTK_MENU_SHELL(menubar),rootmenu);
   rootmenu = gtk_menu_item_new_with_label(" 编辑 ");
   editmenu = gtk_menu_new();//编辑菜单
   menuitem = gtk_image_menu_item_new_from_stock
      (GTK_STOCK_CUT,accel_group);
   gtk_menu_shell_append(GTK_MENU_SHELL(editmenu),menuitem);
   g_signal_connect(G_OBJECT(menuitem),"activate",
      G_CALLBACK(on_edit_cut_activate),NULL);
   menuitem = gtk_image_menu_item_new_from_stock
      (GTK_STOCK_COPY,accel_group);
   gtk_menu_shell_append(GTK_MENU_SHELL(editmenu),menuitem);
   g_signal_connect(G_OBJECT(menuitem),"activate",
      G_CALLBACK(on_edit_copy_activate),NULL);
   menuitem = gtk_image_menu_item_new_from_stock
      (GTK_STOCK_PASTE,accel_group);
   gtk_menu_shell_append(GTK_MENU_SHELL(editmenu),menuitem);
   g_signal_connect(G_OBJECT(menuitem),"activate",
      G_CALLBACK(on_edit_paste_activate),NULL);
   menuitem = gtk_image_menu_item_new_from_stock
      (GTK_STOCK_FIND,accel_group);
   gtk_menu_shell_append(GTK_MENU_SHELL(editmenu),menuitem);
   g_signal_connect(G_OBJECT(menuitem),"activate",
      G_CALLBACK(on_edit_find_activate),NULL);
   gtk_widget_show(rootmenu);
   gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu),editmenu);
   gtk_menu_shell_append(GTK_MENU_SHELL(menubar),rootmenu);
   rootmenu = gtk_menu_item_new_with_label(" 帮助 ");
   helpmenu = gtk_menu_new();
   menuitem = gtk_image_menu_item_new_from_stock
      (GTK_STOCK_HELP,accel_group);
   gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu),menuitem);
   g_signal_connect(G_OBJECT(menuitem),"activate",
      G_CALLBACK(on_help_help_activate),NULL);
   menuitem = gtk_menu_item_new_with_label(" 关于 ");
   gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu),menuitem);
   g_signal_connect(G_OBJECT(menuitem),"activate",
      G_CALLBACK(on_help_about_activate),NULL);
   gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu),helpmenu);
   gtk_menu_shell_append(GTK_MENU_SHELL(menubar),rootmenu);
   return menubar ;
}
GtkWidget* create_toolbar (GtkWidget* window)
{
   GtkWidget* toolbar ;
   toolbar = gtk_toolbar_new();
   gtk_toolbar_insert_stock(GTK_TOOLBAR(toolbar),
      GTK_STOCK_NEW,
      "创建一个新文件","新建",
      GTK_SIGNAL_FUNC(on_file_new_activate),
      window,-1);
   gtk_toolbar_insert_stock(GTK_TOOLBAR(toolbar),
      GTK_STOCK_OPEN,
      "打开一个文件","打开",
      GTK_SIGNAL_FUNC(on_file_open_activate),
      toolbar,-1);
   gtk_toolbar_insert_stock(GTK_TOOLBAR(toolbar),
      GTK_STOCK_SAVE,
      "保存当前文件","保存",
      GTK_SIGNAL_FUNC(on_file_save_activate),
      toolbar,-1);
   return toolbar;
}
///////////////////////////////////////////////////////////////////////////////////////////////////a
///////////////////////////////////////////////////////////////////////////////////////////////////a
///////////////////////////////////////////////////////////////////////////////////////////////////a
///////////////////////////////////////////////////////////////////////////////////////////////////a
/* 主函数文件 main.c*/
//#include <gtk/gtk.h>
//#include "callbacks.h"
//#include "interface.h"
int main (int argc , gchar* argv[])
{
   GtkWidget * window ;
   gtk_init(&argc,&argv);
   window = create_window();
   g_signal_connect(G_OBJECT(window),"delete_event",
      G_CALLBACK(on_window_delete_event),NULL);
   gtk_widget_show(window);
   gtk_main();
   return FALSE;
}
