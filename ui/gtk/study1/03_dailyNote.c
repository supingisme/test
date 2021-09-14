/* 每日提示 tips.c */
#include <gtk/gtk.h>
//XPM格式的图像数据，以C语言源代码形式存于文件中
static char * book_open_xpm[] = {
   "16 16 4 1",
   " c None s None",
   ". c black",
   "X c #808080",
   "o c white",
   " ",
   " .. ",
   " .Xo. ... ",
   " .Xoo. ..oo. ",
   " .Xooo.Xooo... ",
   " .Xooo.oooo.X. ",
   " .Xooo.Xooo.X. ",
   " .Xooo.oooo.X. ",
   " .Xooo.Xooo.X. ",
   " .Xooo.oooo.X. ",
   " .Xoo.Xoo..X. ",
   " .Xo.o..ooX. ",
   " .X..XXXXX. ",
   " ..X....... ",
   " .. ",
   " "};
//自定义提示信息
static gchar *info[5] = {
   "此软件用于测试每日提示功能的实现，如果你发现问题请及时回复。",
   "我们的目的是把GTK+2.0的大多数功能奉献给每一位自由软件爱好者和开发者。",
   "每一位Linux的支持者都会让我们增加一分信心，Linux最终仍是台式计算机操作系统。",
   "计算机软件技术是一种科学技术，它和人类历史上其他的科学技术一样，是允许每一人自由使用的。",
   "当前你测试完此程序后，请设法把它附加到你创作的软件当中去，这是你成功的第一步。"
};
static GtkWidget *window; //主窗口
static GtkWidget *frame; //框架
static GtkWidget *pre_button; //上一提示按钮
static GtkWidget *next_button; //下一提示按钮
static GtkWidget *label; //提示信息内容标签
static GtkWidget *title; //框架的标题
gint current_info = 0 ;//当前提示信息计数
GtkWidget* create_title (GtkWidget *data)
{ //创建框架控件的标题
   GtkWindow *title;
   GtkWidget *hbox;
   GtkWidget *image;
   GtkWidget *label;
   GdkPixmap *pixmap;
   GdkBitmap *mask;
   pixmap = gdk_pixmap_create_from_xpm_d(
                  data->window,&mask,
                  &GTK_WIDGET(data)->style->white,
                  book_open_xpm);
   image = gtk_image_new_from_pixmap(pixmap,NULL);
   label = gtk_label_new("新的标题");
   hbox = gtk_hbox_new(FALSE,0);
   gtk_box_pack_start(GTK_BOX(hbox),image,FALSE,FALSE,2);
   gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,FALSE,2);
   return hbox ;
}
GtkWidget* create_button (gchar* stockid,gchar* title)
{ //创建带图像的按钮
   GtkWidget *button;
   GtkWidget *image;
   GtkWidget *label;
   GtkWidget *hbox;
   image = gtk_image_new_from_stock(stockid,GTK_ICON_SIZE_MENU);
   label = gtk_label_new(title);
   hbox = gtk_hbox_new(FALSE,0);
   gtk_box_pack_start(GTK_BOX(hbox),image,FALSE,FALSE,3);
   gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,FALSE,3);
   button = gtk_button_new();
   gtk_container_add(GTK_CONTAINER(button),hbox);
   return button;
}
void pre_info (GtkButton *button,gpointer data)
{ //上一提示
   gint i ;
   i = current_info - 1 ;
   if(i == -1) return ;
   if(i == 0 ) gtk_widget_set_sensitive(pre_button,FALSE);
   current_info = i ;
   gtk_widget_set_sensitive(next_button,TRUE);
   gtk_label_set_text(GTK_LABEL(label),info[current_info]);
}
void next_info (GtkButton *button,gpointer data)
{ //下一提示
   gint i ;
   i = current_info + 1 ;
   if(i == 5) return ;
   if(i == 4) gtk_widget_set_sensitive(next_button,FALSE);
   current_info = i ;
   gtk_widget_set_sensitive(pre_button,TRUE);
   gtk_label_set_text(GTK_LABEL(label),info[current_info]);
}
int main ( int argc , char* argv[])
{
   GtkWidget *hbox ;
   GtkWidget *vbox;
   GtkWidget *bbox;
   GtkWidget *button;
   GtkWidget *image;
   GtkWidget *title;
   gtk_init(&argc,&argv);
   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   g_signal_connect(G_OBJECT(window),"delete_event",
         G_CALLBACK(gtk_main_quit),NULL);
   gtk_window_set_title(GTK_WINDOW(window),"每日提示");
   gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
   gtk_container_set_border_width(GTK_CONTAINER(window),10);
   gtk_widget_realize(window);
   vbox = gtk_vbox_new(FALSE,0);
   gtk_container_add(GTK_CONTAINER(window),vbox);
   hbox = gtk_hbox_new(FALSE,0);
   gtk_box_pack_start(GTK_BOX(vbox),hbox,TRUE,TRUE,5);
   image = gtk_image_new_from_file("l.bmp");
   gtk_box_pack_start(GTK_BOX(hbox),image,FALSE,FALSE,5);
   frame = gtk_frame_new(NULL);
   title = create_title(window);
   gtk_frame_set_label_widget(GTK_FRAME(frame),title);
   gtk_box_pack_start(GTK_BOX(hbox),frame,TRUE,TRUE,5);
   label = gtk_label_new(NULL);
   gtk_label_set_text(GTK_LABEL(label),info[0]);
   gtk_label_set_line_wrap(GTK_LABEL(label),TRUE);
   gtk_container_add(GTK_CONTAINER(frame),label);
   bbox = gtk_hbutton_box_new();
   gtk_button_box_set_layout(GTK_BUTTON_BOX(bbox),GTK_BUTTONBOX_END);
   gtk_box_set_spacing(GTK_BOX(bbox),5);
   gtk_box_pack_start(GTK_BOX(vbox),bbox,FALSE,FALSE,5);
   button = gtk_check_button_new_with_label("每次启动时显示");
   gtk_box_pack_start(GTK_BOX(bbox),button,FALSE,FALSE,5);
   pre_button = create_button(GTK_STOCK_GO_BACK,"上一提示");
   gtk_widget_set_sensitive(pre_button,FALSE);
   g_signal_connect(G_OBJECT(pre_button),"clicked",
         G_CALLBACK(pre_info),NULL);
   gtk_box_pack_start(GTK_BOX(bbox),pre_button,FALSE,FALSE,5);
   next_button = create_button(GTK_STOCK_GO_FORWARD,"下一提示");
   g_signal_connect(G_OBJECT(next_button),"clicked",
         G_CALLBACK(next_info),NULL);
   gtk_box_pack_start(GTK_BOX(bbox),next_button,FALSE,FALSE,5);
   button = gtk_button_new_from_stock(GTK_STOCK_OK);
   g_signal_connect(G_OBJECT(button),"clicked",
         G_CALLBACK(gtk_main_quit),NULL);
   gtk_box_pack_start(GTK_BOX(bbox),button,FALSE,FALSE,5);
   gtk_widget_show_all(window);
   gtk_main();
   return FALSE;
}
