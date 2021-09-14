#include <gtk/gtk.h>

int main(int argc,char *argv[])
{
    GtkWidget *window;
    GtkTable *table;

    GtkWidget *button1;
    GtkWidget *button2;

    gtk_init(&argc,&argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"test");
    gtk_window_set_default_size(GTK_WINDOW(window),350,300);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);

    table = gtk_table_new(5,5,FALSE);

    button1 = gtk_button_new_with_label("button1");
    button2 = gtk_button_new_with_label("button2");

    gtk_table_attach(GTK_TABLE(table),button1,0,4,0,1,GTK_FILL | GTK_EXPAND,GTK_FILL,1,1);
    gtk_table_set_col_spacing(GTK_TABLE(table),0,4);
    gtk_table_attach(GTK_TABLE(table),button2,4,5,0,1,GTK_FILL,GTK_FILL,1,1);

    gtk_container_add(GTK_CONTAINER(window),table);

    g_signal_connect_swapped(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),G_OBJECT(window));

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
