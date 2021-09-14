#include "common_func.h"

/*
  @Description: 从一个图片中获取信息得到pixbuf
  @param:       gchar filename
*/
GdkPixbuf *create_pixbuf(const gchar* filename)
{
	GdkPixbuf *pixbuf;
    GError *error = NULL;
    /*
     * 函数gdk_pixbuf_new_from_file() 从一个图片文件中加载图象数据，从而生成一个新的 pixbuf，
     * 至于文件中包含图象的格式，是由系统自动检测的。如果该函数返回值是NULL 的话，程序就会出现错误。
    */
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);
    if(!pixbuf) {
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }
    return pixbuf;	

}

//根据菜单栏的选择(check)控制一些构件的显示和隐藏
void toggle_display(GtkWidget *widget, gpointer oneofwidget)
{
    if (gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget))) {
        gtk_widget_show(oneofwidget);
    } else {
        gtk_widget_hide(oneofwidget);
    }
}
