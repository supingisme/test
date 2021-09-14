#include <gtk/gtk.h>

static GdkPixmap *pixmap = NULL;
GdkGC *my_gc_red;
GdkColor color;

int my_configure_event(GtkWidget *widget , GdkEventConfigure *event)
{
      if(pixmap)
          g_object_unref(pixmap);
      pixmap = gdk_pixmap_new(widget->window , 
                  widget->allocation.width , 
                  widget->allocation.height , 
                  -1);
      gdk_draw_rectangle(pixmap , widget->style->white_gc , 
                  TRUE , 0 , 0 , 
                  widget->allocation.width , 
                  widget->allocation.height);

      my_gc_red = gdk_gc_new(widget->window);
      color.red = 30000;
      color.green = 0;
      color.blue = 30000;
      gdk_gc_set_rgb_fg_color(my_gc_red , &color);    

      return 0;
}

int my_expose_event(GtkWidget *widget , GdkEventExpose *event , gpointer data)
{
      gdk_draw_drawable(widget->window , 
              widget->style->fg_gc[GTK_WIDGET_STATE(widget)] ,
              pixmap , 0 , 0 , 0 , 0 , 
              widget->allocation.width , 
              widget->allocation.height);    

      return 0;
}

int my_draw(GtkWidget *widget , double x , double y , int type)
{
      switch(type){
          case 1:
              gdk_draw_rectangle(pixmap , 
                      widget->style->black_gc , 
                      FALSE ,     
                      x , y , 10 , 10);
              gtk_widget_queue_draw_area(widget , 
                          x , y , 10 , 10);
              break;
          case 2:
              gdk_draw_rectangle(pixmap , 
                      my_gc_red , 
                      TRUE ,     
                      x , y , 15 , 15);
              gtk_widget_queue_draw_area(widget , 
                          x , y , 15 , 15);
              break;
          case 3:
              gdk_draw_line(pixmap , my_gc_red , 
                      x , y , x + 15 , y - 15);
              gtk_widget_queue_draw_area(widget , 
                      x , y - 15 , 15 , 15);
              break;
          default:
              printf("....\n");
              break;
      }
    
      return 0;
}
int my_button_press_event(GtkWidget *widget , GdkEventButton *event)
{
      my_draw(widget , event->x , event->y , event->button);    
      printf("x=%lf y=%lf\n" , event->x , event->y);

      return 0;    
}
int my_clear(GtkWidget *widget , GtkWidget *area)
{
      gdk_draw_rectangle(pixmap , 
              area->style->white_gc , 
              TRUE , 0 , 0 , 
              area->allocation.width , 
              area->allocation.height);
      gtk_widget_queue_draw(area);

      return 0;
}
int my_quit(GtkWidget *widget , gpointer data)
{
      gtk_main_quit();
    
      return 0;
}

int main(int argc , char *argv[])
{
      GtkWidget *window;
      GtkWidget *drawing_area;
      GtkWidget *vbox;
      GtkWidget *bt_clear;
      GtkWidget *bt_quit;

      gtk_init(&argc , &argv);
    
      window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
      gtk_widget_set_name(window , "Test drawing_area");
      gtk_widget_set_size_request(window , 300 , 200);
      gtk_container_set_border_width(GTK_CONTAINER(window) , 2);
      gtk_window_set_resizable(GTK_WINDOW(window) , FALSE);

      vbox = gtk_vbox_new(FALSE , 0);
      gtk_container_add(GTK_CONTAINER(window) , vbox);
      gtk_widget_show(vbox);
    
      g_signal_connect(G_OBJECT(window) , "destroy" , 
              G_CALLBACK(my_quit) , NULL);

      drawing_area = gtk_drawing_area_new();
      gtk_box_pack_start(GTK_BOX(vbox) , drawing_area , TRUE , TRUE , 0);
      gtk_widget_show(drawing_area);
      g_signal_connect(G_OBJECT(drawing_area) , "configure_event" , 
              G_CALLBACK(my_configure_event) , NULL);
      g_signal_connect(G_OBJECT(drawing_area) , "expose_event" , 
              G_CALLBACK(my_expose_event) , NULL);
      g_signal_connect(G_OBJECT(drawing_area) , "button_press_event" , 
              G_CALLBACK(my_button_press_event) , NULL);
      gtk_widget_set_events(drawing_area , GDK_BUTTON_PRESS_MASK);
    
      bt_clear = gtk_button_new_with_label("clear");
      gtk_box_pack_start(GTK_BOX(vbox) , bt_clear , FALSE , FALSE , 0);
      g_signal_connect(G_OBJECT(bt_clear) , "clicked" , 
              G_CALLBACK(my_clear) , drawing_area);
      gtk_widget_show(bt_clear);
    
      bt_quit = gtk_button_new_with_label("quit");
      gtk_box_pack_start(GTK_BOX(vbox) , bt_quit , FALSE , FALSE , 0);
      g_signal_connect(G_OBJECT(bt_quit) , "clicked" , 
              G_CALLBACK(my_quit) , window);
      gtk_widget_show(bt_quit);

      gtk_widget_show(window);

      gtk_main();

      return 0;
}

