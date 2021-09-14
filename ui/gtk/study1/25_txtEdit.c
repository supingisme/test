#include <gtk/gtk.h> 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
GtkWidget *text_view; 
GtkTextBuffer *buffer; 
GtkTextIter *Iter; 

void button_event(GtkWidget *widget,gpointer *data) 
{
    const gchar *text={"How are you!\n"};
    GtkTextIter start,end; 
    gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buffer),&start,&end);
    gtk_text_buffer_insert(GTK_TEXT_BUFFER(buffer),&end,text,strlen(text));
}
 int main(int argc,char *argv[ ]) 
{ 
    GtkWidget *window;
    GtkWidget *button; 
    GtkWidget *box; 

    gtk_init(&argc,&argv); 
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL); 
    gtk_widget_set_size_request(window,400,300); 
    g_signal_connect(GTK_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL); 

    box=gtk_vbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(window),box);  

    text_view=gtk_text_view_new();
    gtk_widget_set_size_request(text_view,400,250); 
    gtk_box_pack_start(GTK_BOX(box),text_view,FALSE,FALSE,0); 

    buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    button=gtk_button_new_with_label("sure");
    gtk_box_pack_start(GTK_BOX(box),button,FALSE,FALSE,5);
 
    gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(button_event),NULL); 
    gtk_widget_show_all(window); 
    gtk_main();
} 

