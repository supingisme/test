/* 坦克游戏 tank.c */
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
enum _FORWARD { LEFT, UP, RIGHT, DOWN } ;
typedef enum _FORWARD Forward; //定义方向类型
void move (Forward fw);
void key_press (GtkWidget* widget,GdkEventKey *event,gpointer data);
static gchar* tank_file[4] = {"u.bmp","r.bmp","d.bmp","l.bmp"};
static GtkWidget *fixed;
static GtkWidget *tank_image;
gint i = 75 ;
gint j = 75 ;
Forward forward = UP ;//定义方向
void move (Forward fw)
{
   switch(fw)
   {
      case UP :
         j = j - 5 ;
         if ( j < 0 ) j = 400 ;
         gtk_image_set_from_file(GTK_IMAGE(tank_image),tank_file[0]);
         gtk_fixed_move(GTK_FIXED(fixed),tank_image,i,j);
         break;
      case DOWN :
         j = j + 5;
         if ( j > 400 ) j = 0 ;
         gtk_image_set_from_file(GTK_IMAGE(tank_image),tank_file[2]);
         gtk_fixed_move(GTK_FIXED(fixed),tank_image,i,j);
         break;
      case LEFT :
         i = i - 5;
         if ( i < 0 ) i = 400 ;
         gtk_image_set_from_file(GTK_IMAGE(tank_image),tank_file[3]);
         gtk_fixed_move(GTK_FIXED(fixed),tank_image,i,j);
         break;
      case RIGHT :
         i = i + 5;
         if ( i > 400 ) i = 0 ;
         gtk_image_set_from_file(GTK_IMAGE(tank_image),tank_file[1]);
         gtk_fixed_move(GTK_FIXED(fixed),tank_image,i,j);
         break;
   }
}
void key_press (GtkWidget* widget,GdkEventKey *event,gpointer data)
{
   switch(event->keyval)
   {
      case GDK_Up :
         forward = UP;
         move(forward);
         break;
      case GDK_Down :
         forward = DOWN;
         move(forward);
         break;
      case GDK_Left :
         forward = LEFT;
         move(forward);
         break;
      case GDK_Right :
         forward = RIGHT;
         move(forward);
         break;
   }
}
//主函数
int main (int argc, char *argv[])
{
   GtkWidget* window;
   GtkWidget* vbox;
   GtkWidget* bbox;
   GtkWidget* sep;
   GtkWidget* frame;
   GtkWidget* button;

   gtk_init(&argc,&argv);

   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(window),"坦克游戏");
   gtk_container_set_border_width(GTK_CONTAINER(window),10);
   g_signal_connect(G_OBJECT(window),"destroy",
      G_CALLBACK(gtk_main_quit),NULL);

   g_signal_connect(G_OBJECT(window),"key_press_event",
      G_CALLBACK(key_press),NULL);////keyboard input

   vbox = gtk_vbox_new(FALSE,0);
   gtk_container_add(GTK_CONTAINER(window),vbox);

   frame = gtk_frame_new(NULL);
   gtk_frame_set_shadow_type(GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);

   fixed = gtk_fixed_new();
   gtk_fixed_set_has_window(GTK_FIXED(fixed),TRUE);
   gtk_widget_set_size_request(fixed,400,400);

   gtk_container_add(GTK_CONTAINER(frame),fixed);
   gtk_box_pack_start(GTK_BOX(vbox),frame,TRUE,TRUE,5);

   sep = gtk_hseparator_new();
   gtk_box_pack_start(GTK_BOX(vbox),sep,FALSE,FALSE,5);

   bbox = gtk_hbutton_box_new();
   gtk_button_box_set_layout(GTK_BUTTON_BOX(bbox),GTK_BUTTONBOX_END);
   gtk_box_pack_start(GTK_BOX(vbox),bbox,FALSE,FALSE,5);

   button = gtk_button_new_from_stock(GTK_STOCK_QUIT);
   g_signal_connect(G_OBJECT(button),"clicked",
      G_CALLBACK(gtk_main_quit),NULL);
   gtk_box_pack_end(GTK_BOX(bbox),button,FALSE,FALSE,5);

   tank_image = gtk_image_new_from_file(tank_file[0]);
   gtk_fixed_put(GTK_FIXED(fixed),tank_image,i,j);
   gtk_widget_show_all(window);
   gtk_main();
   return FALSE ;
}
