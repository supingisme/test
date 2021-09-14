#include <gtk/gtk.h>

static void destroy( GtkWidget *widget, gpointer data )
{
    gtk_main_quit ();
}
static gboolean my_expose( GtkWidget      *da,
                           GdkEventExpose *event,
                           gpointer        data )
{
    GdkGC *gc1, *gc2, *gc;  /*gc1为矩形，gc2为文字*/

    GdkColor color;

    gc1 = gdk_gc_new( da->window );

    color.red = 10000;
    color.green = 20000;
    color.blue = 30000;
    gdk_gc_set_rgb_fg_color(gc1, &color );

    gc2 = gdk_gc_new( da->window );

    color.red = 1;
    color.green = 2;
    color.blue = 3;
    gdk_gc_set_rgb_fg_color( gc2, &color );

    gc = gc1;
    gdk_draw_rectangle( da->window, gc, TRUE,//fill or not
                           50, 50, 100, 100 );  /*（fx、fz、dx、dz）*/
    gc = gc2;
    gdk_draw_arc( da->window, gc, TRUE, //fill or not
                      50, 50, 100, 100, 0, 270 * 64 );  /*（fx、fz、dx、dz、0、arc）*/
 
    PangoLayout *layout = gtk_widget_create_pango_layout( da, "This is a cube \nand a circle." );

    PangoFontDescription *fontdesc = pango_font_description_from_string( "Luxi Mono 8" );

    pango_layout_set_font_description( layout, fontdesc ); 

    gdk_draw_layout( da->window, gc1, 50, 155, layout );

    pango_font_description_free( fontdesc );

    g_object_unref( layout );
 
    g_object_unref( G_OBJECT(gc1) );
    g_object_unref( G_OBJECT(gc2) );
   
    return TRUE;
}
int main( int  argc, char *argv[] )
{
    GtkWidget *window;
    GtkWidget *da; //drawing area
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect( G_OBJECT (window), "destroy",
                G_CALLBACK (destroy), NULL );
    
    da = gtk_drawing_area_new ();
    /* set a minimum size */
    gtk_widget_set_size_request( da, 200, 200 );
    gtk_container_add( GTK_CONTAINER(window), da );
    g_signal_connect( da, "expose_event", G_CALLBACK(my_expose), NULL );
    gtk_widget_show_all( window ); //simply show all widgets
    gtk_main();
    
    return 0;
}
