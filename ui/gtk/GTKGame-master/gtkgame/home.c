#include <gtk/gtk.h>

int main(int argc, char *argv[]){
  GtkWidget *window;

  //初始化GTK+程序
  gtk_init(&argc,&argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  //生成窗体之后显示
  gtk_widget_show(window);

  //进入主循环
  gtk_main();
  
  return 0;
}
