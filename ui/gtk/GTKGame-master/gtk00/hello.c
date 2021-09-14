#include <gtk/gtk.h>

int main(int argc,char *argv[])
{
	GtkWidget *window;

	// 初始化GTK+程序，必不可少
	gtk_init(&argc,&argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	// 生成窗体之后需要显示
	gtk_widget_show(window);
	
	// 相当于让程序进入主循环，等待事件的发生
	gtk_main();

	return 0;
}
