#include <gtk/gtk.h>
#include <stdlib.h>

GtkWidget *file,*_vel,*_deta,*_epsilu;


void file_OK( GtkWidget *w, gpointer *data )
{
    gtk_entry_set_text (GTK_ENTRY (data),
                   gtk_file_selection_get_filename (GTK_FILE_SELECTION (file)));
    gtk_widget_destroy (file);
}
void select_file(GtkWidget *w,gpointer *data)
{
    file= gtk_file_selection_new ("File selection");

    g_signal_connect (G_OBJECT (GTK_FILE_SELECTION (file)->ok_button), "clicked",
                     G_CALLBACK (file_OK), data);
    g_signal_connect_swapped (G_OBJECT (GTK_FILE_SELECTION (file)->cancel_button), "clicked",
                             G_CALLBACK (gtk_widget_destroy), NULL);
    gtk_widget_show (file);
}
/* 创建一个新的横向盒,它包含一个图像和一个标签,并返回这个盒。*/
GtkWidget *xpm_label_box( gchar *xpm_filename, gchar *label_text )
{
   GtkWidget *box;
   GtkWidget *label;
   GtkWidget *image;
/* 为图像和标签创建盒 */
   box = gtk_hbox_new (FALSE, 0);
   gtk_container_set_border_width (GTK_CONTAINER (box), 10);
/* 创建一个图像 */
   image = gtk_image_new_from_file (xpm_filename);
/* 为按钮创建一个标签 */
   label = gtk_label_new (label_text);
/* 把图像和标签组装到盒子里 */
   gtk_box_pack_start (GTK_BOX (box), image, TRUE, TRUE, 3);
   gtk_box_pack_start (GTK_BOX (box), label, TRUE, TRUE, 3);
   gtk_widget_show (image);
   gtk_widget_show (label);
   return box;
}
int main( int argc, char *argv[] )
{
    GtkWidget *window;
    GtkWidget *button;

    GtkWidget *label;
    GtkWidget *table;

    GtkWidget *box;

    gtk_init (&argc, &argv);

    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"RT's VTI model");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    g_signal_connect(GTK_OBJECT(window),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
     
    table=gtk_table_new(3,8,TRUE);
    gtk_container_add(GTK_CONTAINER(window),table);

    label=gtk_label_new("Input Filename:");
    gtk_table_attach_defaults(GTK_TABLE(table),label,0,2,0,1);

/*******************  vel *******************/
    label=gtk_label_new("vel:");
    gtk_table_attach_defaults(GTK_TABLE(table),label,0,1,1,2);
    _vel=gtk_entry_new_with_max_length(100);
    gtk_entry_set_text (GTK_ENTRY (_vel), "vel.dat");
    gtk_table_attach_defaults(GTK_TABLE(table),_vel,1,7,1,2);
    button=gtk_button_new();
    box = xpm_label_box ("pic/dir2.jpg", NULL);
    gtk_container_add (GTK_CONTAINER (button), box);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(select_file),_vel);
    gtk_table_attach_defaults(GTK_TABLE(table),button,7,8,1,2);

/*******************  epsilu *******************/
    label=gtk_label_new("epsilu:");
    gtk_table_attach_defaults(GTK_TABLE(table),label,0,1,2,3);
    _epsilu=gtk_entry_new_with_max_length(100);
    gtk_entry_set_text (GTK_ENTRY (_epsilu), "epsilu.dat");
    gtk_table_attach_defaults(GTK_TABLE(table),_epsilu,1,7,2,3);
    //button=gtk_button_new_with_label("...");
    button=gtk_button_new();
    box = xpm_label_box ("pic/dir2.jpg", NULL);
    gtk_container_add (GTK_CONTAINER (button), box);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(select_file),_epsilu);
    gtk_table_attach_defaults(GTK_TABLE(table),button,7,8,2,3);

/*******************  deta *******************/
    label=gtk_label_new("deta:");
    gtk_table_attach_defaults(GTK_TABLE(table),label,0,1,3,4);
    _deta=gtk_entry_new_with_max_length(100);
    gtk_entry_set_text (GTK_ENTRY (_deta), "deta.dat");
    gtk_table_attach_defaults(GTK_TABLE(table),_deta,1,7,3,4);
    //button=gtk_button_new_with_label("...");
    button=gtk_button_new();
    box = xpm_label_box ("pic/dir2.jpg", NULL);
    gtk_container_add (GTK_CONTAINER (button), box);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(select_file),_deta);
    gtk_table_attach_defaults(GTK_TABLE(table),button,7,8,3,4);



    gtk_widget_show_all(window);
    gtk_main ();
    return 0;
}
