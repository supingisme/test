#include <gtk/gtk.h>

gint count = 0;
char buf[5];

//增加按钮每次按下，label中的数就会加1
void increase(GtkWidget* widget,gpointer label)
{
    count++;
    sprintf(buf,"%d",count);
    gtk_label_set_text(label,buf);
}

//减小按钮每次按下，label中的数就会减小1
void decrease(GtkWidget *widget,gpointer label)
{
    count--;
    sprintf(buf,"%d",count);
    gtk_label_set_text(label,buf);
}

int main(int argc,char *argv[])
{

    GtkWidget *label;
    GtkWidget *window;
    GtkWidget *frame;
    GtkWidget *plus;
    GtkWidget *minus;

    gtk_init(&argc,&argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  //新建窗口
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);  //窗口放在屏幕中间
    gtk_window_set_default_size(GTK_WINDOW(window),250,180); //设置窗口的大小
    gtk_window_set_title(GTK_WINDOW(window),"+-");  //设置窗口的标题

    frame = gtk_fixed_new(); //这个是GTK+布局中的一种，后面讲到
    gtk_container_add(GTK_CONTAINER(window),frame); //向window容器中添加布局

    plus = gtk_button_new_with_label("+");  //新建按钮
    gtk_widget_set_size_request(plus,80,35); //设置增加按钮的大小
    gtk_fixed_put(GTK_FIXED(frame),plus,50,20);  //将按钮放在布局中

    minus = gtk_button_new_with_label("-"); //新建按钮
    gtk_widget_set_size_request(minus,80,35); //设置大小
    gtk_fixed_put(GTK_FIXED(frame),minus,50,80);

    label = gtk_label_new("0");   //新建标签
    gtk_fixed_put(GTK_FIXED(frame),label,190,58);

    gtk_widget_show_all(window);

    //信号
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect(plus,"clicked",G_CALLBACK(increase),label);
    g_signal_connect(minus,"clicked",G_CALLBACK(decrease),label);

    gtk_main();

    return 0;

}

























