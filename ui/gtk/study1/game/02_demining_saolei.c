#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <time.h>
#include <unistd.h>
#include <gtk/gtk.h>

 
#define AREA_MAX_X    9
#define AREA_MAX_Y    9
#define MINE_NUM      10
#define TIMEOUT       99
#define MINE_FLAG     -1
#define ZERO_MINE     0


typedef struct {
    int x;
    int y;
} point_t;


void orz_clean_zero_mine_area(int x, int y);
void orz_quit_dialog(char *str);

/* */
void orz_lclicked_event(GtkButton *button, point_t *point);
void orz_rclicked_event(GtkButton *button, point_t *point);
void orz_doubleclicked_event();
void orz_restart_event();
void orz_timer_event(GtkLabel *data);


/* */
gboolean timer(gpointer data);
void button_clicked(GtkWidget *widget, GdkEventButton *event, gpointer data);

 
/*
  * g_area用于保存该点是否存在mine，以及周围有多少mine
  * g_button用于保存全局的按钮信息
 */
 GtkWidget *l_mines;
 int        mark_mines;
 int        g_area[AREA_MAX_X][AREA_MAX_Y];
GtkButton *g_button[AREA_MAX_X][AREA_MAX_Y];

 
 /*****************************************************************************/
 int main(int argc, char **argv)
 {
     GtkWidget *window;
     GtkWidget *table;
     GtkWidget *b_restart;
     GtkWidget *l_time;

     gtk_init(&argc, &argv);
 
     window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
     gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
     gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
     gtk_container_set_border_width(GTK_CONTAINER(window), 5);
 
     table = gtk_table_new(AREA_MAX_Y + 1, AREA_MAX_X, TRUE);
    gtk_table_set_row_spacings(GTK_TABLE(table), 1);
     gtk_table_set_col_spacings(GTK_TABLE(table), 1);
 
     char label[5] = {0};
    sprintf(label, "%d", MINE_NUM);
     l_mines = gtk_label_new(label);
 
     sprintf(label, "%d", TIMEOUT);
     l_time  = gtk_label_new(label);
 
     gtk_table_attach_defaults(GTK_TABLE(table), l_mines, 0, 2, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(table), l_time,  8, 9, 0, 1);

     gtk_timeout_add(1000, timer, l_time);
 
     b_restart = gtk_button_new_with_label("Re");
    gtk_table_attach_defaults(GTK_TABLE(table), b_restart, 4, 5, 0, 1);
 
     point_t point[AREA_MAX_X][AREA_MAX_Y];
      int i, j;
     for (j = 1; j < 10; ++j) {
          for (i = 0; i < 9; ++i) {
             point[i][j-1].x = i;
             point[i][j-1].y = j - 1;
 
             g_button[i][j-1] = (GtkButton*)gtk_button_new();
 
             g_signal_connect(G_OBJECT(g_button[i][j-1]), "button_press_event", G_CALLBACK(button_clicked), &point[i][j-1]);
             gtk_table_attach_defaults(GTK_TABLE(table), (GtkWidget*)g_button[i][j-1], i, i+1, j, j+1);
         }
     }
 
     gtk_container_add(GTK_CONTAINER(window), table);
 
     g_signal_connect_swapped(G_OBJECT(window), "destroy",  G_CALLBACK(gtk_main_quit), NULL);
 
     gtk_widget_show_all(window);
 
     /*
     * 初始化游戏
      */
     (void)orz_init();
 

     /*
     * 由GTK控制循环
      */
     gtk_main();
 
     return 0;
 }
 
 /* */
 gboolean timer(gpointer data)
 {
     orz_timer_event((GtkLabel*)data);
     return TRUE;
 }
 
 void button_clicked(GtkWidget *widget, GdkEventButton *event, gpointer data)
{
     if (event->type == GDK_BUTTON_PRESS) {
         if (event->button == 1) {
             orz_lclicked_event((GtkButton*)widget, (point_t*)data);
         }
 
         if (event->button == 3) {
             orz_rclicked_event((GtkButton*)widget, (point_t*)data);
         }
     }
 
     if (event->type == GDK_2BUTTON_PRESS) {
         if (event->button == 1) {
             printf("double button clicked\n");
         }
    }
}
 
 /*
 * 游戏初始化
  */
 int orz_init()
 {
     mark_mines = MINE_NUM;
     memset(g_area, 0, AREA_MAX_X * AREA_MAX_Y * sizeof(int));

     srandom((int)time(NULL));

    int x = 0, y = 0;
     int i;
     for (i = 0; i < MINE_NUM; ++i) {
         x = random() % AREA_MAX_X;
        y = random() % AREA_MAX_Y;
 
        if (g_area[x][y] == MINE_FLAG) {
             --i;
         }
         else {
             g_area[x][y] = MINE_FLAG;

             int n;
             for (n = 0; n < 9; ++n) {
                 if (n != 4
                     && orz_check_point_in_area(x + n % 3 - 1, y + n / 3 - 1) == 0
                    && g_area[x + n % 3 - 1][y + n / 3 - 1] != MINE_FLAG)
                 {
                    ++g_area[x + n % 3 - 1][y + n / 3 - 1];
                 }
             }
         }
    }
 
     return 0;
 }
 
 int orz_check_point_in_area(int x, int y)
{
     if (x < 0 || x >= AREA_MAX_X || y < 0 || y >= AREA_MAX_Y) {
        return -1;
    }

     return 0;
 }
 
 void orz_clean_zero_mine_area(int x, int y)
 {
     if (orz_check_point_in_area(x-1, y) == 0
         && gtk_button_get_relief(g_button[x-1][y]) != GTK_RELIEF_NONE
        && g_area[x-1][y] == ZERO_MINE)
    {
         gtk_button_set_relief(g_button[x-1][y], GTK_RELIEF_NONE);
         orz_clean_zero_mine_area(x-1, y);
     }
 
   if (orz_check_point_in_area(x+1, y) == 0
             && gtk_button_get_relief(g_button[x+1][y]) != GTK_RELIEF_NONE
            && g_area[x+1][y] == ZERO_MINE)
    {
         gtk_button_set_relief(g_button[x+1][y], GTK_RELIEF_NONE);
         orz_clean_zero_mine_area(x+1, y);
     }

     if (orz_check_point_in_area(x, y-1) == 0
         && gtk_button_get_relief(g_button[x][y-1]) != GTK_RELIEF_NONE
         && g_area[x][y-1] == ZERO_MINE)
     {
        gtk_button_set_relief(g_button[x][y-1], GTK_RELIEF_NONE);
        orz_clean_zero_mine_area(x, y-1);
    }

     if (orz_check_point_in_area(x, y+1) == 0
         && gtk_button_get_relief(g_button[x][y+1]) != GTK_RELIEF_NONE
        && g_area[x][y+1] == ZERO_MINE)
     {
         gtk_button_set_relief(g_button[x][y+1], GTK_RELIEF_NONE);
         orz_clean_zero_mine_area(x, y+1);
    }
 }
 
 void orz_quit_dialog(char *str)
 {
     GtkWidget *dialog;
     GtkWidget *b_quit;
     GtkWidget *table;
 
     dialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
     gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
     gtk_window_set_title(GTK_WINDOW(dialog), str);
 
     table = gtk_table_new(3, 8, TRUE);
    
    b_quit = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped(G_OBJECT(b_quit), "clicked", G_CALLBACK(gtk_main_quit), NULL);
 
     gtk_table_attach_defaults(GTK_TABLE(table), b_quit, 3, 5, 1, 2);
    
     gtk_container_add(GTK_CONTAINER(dialog), table);
 
     gtk_widget_show_all(dialog);
}
 

 /* */
 void orz_lclicked_event(GtkButton *button, point_t *point)
{
     char label[5] = {0};

     if (g_area[point->x][point->y] == MINE_FLAG) {
        orz_quit_dialog("bang...");
     }
     else if (g_area[point->x][point->y] == ZERO_MINE) {
         if (gtk_button_get_relief(g_button[point->x][point->y]) != GTK_RELIEF_NONE) {
            gtk_button_set_relief(button, GTK_RELIEF_NONE);
             orz_clean_zero_mine_area(point->x, point->y);
        }
     }
     else {
         sprintf(label, "%d", g_area[point->x][point->y]);
        gtk_button_set_relief(button, GTK_RELIEF_NONE);
         gtk_button_set_label(button, label);
     }
 }
 
 void orz_rclicked_event(GtkButton *button, point_t *point)
 {
     static int actual_find_mine = 0;
     char label[10] = {0};
 
    if (gtk_button_get_relief(button) != GTK_RELIEF_NONE) {
        if (gtk_button_get_label(button) == NULL)
        {
             gtk_button_set_label(button, "F");
             --mark_mines;
             sprintf(label, "%d", mark_mines);
            gtk_label_set_text((GtkLabel*)l_mines, label);
             if (g_area[point->x][point->y] == MINE_FLAG) {
                ++actual_find_mine;
             }
 
             if (actual_find_mine == MINE_NUM) {
                 orz_quit_dialog("win...");
            }
        }
        else{
             gtk_button_set_label(button, "");
             gtk_button_set_label(button, NULL);
             ++mark_mines;
            sprintf(label, "%d", mark_mines);
             gtk_label_set_text((GtkLabel*)l_mines, label);
        }
     }
}

 void orz_doubleclicked_event()
 {
 }
 
 void orz_restart_event()
{
 }

 void orz_timer_event(GtkLabel *label)
 {
     static int flag = 0;
     static int time = TIMEOUT;
     char s_time[10] = {0};

    if (flag == 1) return;

     if (time < 0) {
         flag = 1;
        orz_quit_dialog("time out");
    }

     sprintf(s_time, "%d", time--);
    gtk_label_set_text(label, s_time);
 }

