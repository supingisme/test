/* 
 * File:   main.c
 * Author: ldd
 *
 * Created on 2012年1月8日, 下午12:38
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <time.h>
#include <string.h>
 
typedef struct ACTIVE_BLOCK_struct{
    int block[4][4];
    int left;//左面有多少个格
    int top;//上面有多少个格
    int height;
    int width;
}ACTIVE_BLOCK;
 
int _block[7][4][4]={
                     {{1,1,1,1},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0}},//----
                     {{1,1,0,0},
                      {1,1,0,0},
                      {0,0,0,0},
                      {0,0,0,0}},//田
                     {{1,1,0,0},
                      {0,1,1,0},
                      {0,0,0,0},
                      {0,0,0,0}},//
                     {{0,1,1,0},
                      {1,1,0,0},
                      {0,0,0,0},
                      {0,0,0,0}},//
                     {{1,1,1,0},
                      {0,0,1,0},
                      {0,0,0,0},
                      {0,0,0,0}},//
                     {{1,1,1,0},
                      {1,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0}},//
                     {{1,1,1,0},
                      {0,1,0,0},
                      {0,0,0,0},
                      {0,0,0,0}}
};//七种block
int width[7];//七种block的宽度
int height[7];//七种block的高度
ACTIVE_BLOCK block;//全局的动态 block
int map[32][16];//地图，最后一位代表有无块其他表示颜色
 
GtkWidget *button;
GtkWidget *table;
GtkWidget *label1;
GtkWidget *label2;
GtkWidget *draw_erea;
int score;//总分
int map_height;//map的总高度，用于消去时减少循环
int turn[4][4]={{30,20,10,0},
                {31,21,11,1},
                {32,22,12,2},
                {33,23,13,3}};//旋转数组
int a[4][4];
gboolean is_create;//是否生成新的block，即最后一个block无法下降了
int time_id;
GdkColor color;
GdkColor color_white;
GdkDrawable *draw_able;
GdkGC *gc;
GdkGC *gc_white;
GtkWidget *window;
GtkWidget *entry;
 
void init()//游戏初始化
{
    int i,j,k;
    score=0;
    map_height=0;
    is_create=TRUE;
    color.blue=0;
    color.red=65535;
    color.green=0;
    color_white.blue=65535;
    color_white.red=65535;
    color_white.green=65535;
    gc=gdk_gc_new(draw_erea->window);
    gc_white=gdk_gc_new(draw_erea->window);
    gdk_gc_set_rgb_fg_color(gc,&color);
    gdk_gc_set_rgb_fg_color(gc_white,&color_white);
    draw_able=draw_erea->window;
     
 
    height[0]=1;
    for(i=1;i<7;i++)
        height[i]=2;
    width[0]=4;
    width[1]=2;
    for(i=2;i<7;i++)
        width[i]=3;
    map[0][0]=1;
    map[0][1]=1;
}
 
void display_map()//显示map的block
{
    int i,j;
    gdk_draw_rectangle(draw_able,gc_white,TRUE,0,0,320,640);
    for(i=0;i<32;i++)
    {
        for(j=0;j<16;j++)
        {
            if(map[i][j]==1)
                gdk_draw_rectangle(draw_able,gc,TRUE,j*20,i*20,15,15);
        }
    }
}
 
void display_block()
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(block.block[i][j]%10==1)
                gdk_draw_rectangle(draw_able,gc,TRUE,(j+block.left)*20,(i+block.top)*20,15,15);
}
 
gboolean check_down(){//检查是否还可以下降
    int i,j,b;//b用来区分block是否在最后一列
    if(block.height+block.top>31)
    {
        return FALSE;
    }
    if(block.left==15&&block.width==1)
        b=1;
    else if(block.left==14&&block.width==2)
        b=2;
    else if(block.left==13&&block.width==3)
        b=3;
    else
        b=4;
    for(i=0;i<block.height;i++)
    {
        for(j=0;j<b;j++)
            if(block.block[i][j]+map[block.top+i+1][block.left+j]%10>1)
                return FALSE;
    }
    return TRUE;
}
 
gboolean check_now()//检查当前状态是否安全
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(a[i][j]+map[block.top+i][block.left+j]%10>1)
                return FALSE;
    return TRUE;
}
 
gboolean check_left_right()//检查左移或右移是否安全
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(block.block[i][j]+map[block.top+i][block.left+j]%10>1)
                return FALSE;
    return TRUE;
}
 
void un_display_block()
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(block.block[i][j]%10==1)
                gdk_draw_rectangle(draw_able,gc_white,TRUE,(j+block.left)*20,(i+block.top)*20,15,15);
}
 
void eliminate(){//一行满了消去
    int i,j,k,temp;
    char a[20];
    for(i=31;i>=31-map_height+1;i--)
    {
        temp=0;
        for(j=0;j<16;j++)
            if(map[i][j]==0)
                break;
        if(j==16)
        {
            for(j=i;j>=31-map_height;j--)
                for(k=0;k<16;k++)
                    map[j][k]=map[j-1][k];
            i++;
            score++;
            gcvt((float)score,3,a);
            gtk_label_set_text(GTK_LABEL(label2),a);
        }
    }
}
 
void down()//下降函数
{
    int i,j,r;
    if(is_create==TRUE)//如果需要生成一个block
    {
        srandom(time(NULL));
        r=rand()%7;
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                block.block[i][j]=_block[r][i][j];
        block.left=6;
        block.top=0;
        block.height=height[r];
        block.width=width[r];
        if(!check_down())///////////////////游戏结束
        {
            g_source_remove(time_id);
        }
        is_create=FALSE;
    }
    else
    {
        block.top++;
        if(!check_down())
        {
            for(i=0;i<block.height;i++)
                for(j=0;j<4;j++)
                    if(map[block.top+i][block.left+j]==0)
                        map[block.top+i][block.left+j]=block.block[i][j];
            if(32-block.top>map_height)
                map_height=32-block.top;
            eliminate();
            is_create=TRUE;
            display_map();
        }
    }
}
 
void timeout()
{
    un_display_block();
    down();
    display_map();
    display_block();
     
    g_source_remove(time_id);
    time_id=g_timeout_add(1000,(GtkFunction)timeout,NULL);
    return ;
}
 
void up()//按下上方向键，即变换形状，采用右旋转
{
    int i,j,temp,k;
  
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            a[i][j]=block.block[turn[i][j]/10][turn[i][j]%10];
    if(check_now()==TRUE)
    {
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                block.block[i][j]=a[i][j];
        temp=block.height;
        block.height=block.width;
        block.width=temp;
        for(i=0;i<3;i++)//左移
        {
            temp=a[0][i]+a[1][i]+a[2][i]+a[3][i];
            if(temp!=0)
                break;
            for(j=0;j<3;j++)
                for(k=0;k<4;k++)
                    block.block[k][j]=block.block[k][j+1];
            for(k=0;k<4;k++)
                    block.block[k][3]=0;
        }
    }
}
 
gboolean expose_event_callback(GtkWidget *widget,GdkEventExpose *event,gpointer data)
{
    display_map();
    display_block();
}
 
gboolean key_value(GtkWidget *widget, GdkEventKey *event, gpointer data)
{
    un_display_block();
    if(strcmp(gdk_keyval_name(event->keyval),"Up")==0)
    {
        up();
    }
    else if(strcmp(gdk_keyval_name(event->keyval),"Down")==0)
    {
        down();
        display_map();
    }
    else if(strcmp(gdk_keyval_name(event->keyval),"Left")==0)
    {
        if(block.left>0)
            block.left--;
        if(check_left_right()==FALSE)
            block.left++;
    }
    else if(strcmp(gdk_keyval_name(event->keyval),"Right")==0)
    {
        if(block.left+block.width-1<15)
            block.left++;
        if(check_left_right()==FALSE)
            block.left--;
    }
    display_block();
    return FALSE;
}
 
int main(int argc, char** argv) {
 
     
    gtk_init(&argc,&argv);
   
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
     gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
     gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
   g_signal_connect(G_OBJECT(window),"destroy",
         G_CALLBACK(gtk_main_quit),NULL);
   gtk_container_set_border_width(GTK_CONTAINER(window),5);
    // gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);




    entry = gtk_entry_new();
    table=gtk_table_new(2,2,FALSE);
    draw_erea=gtk_drawing_area_new();
    label1=gtk_label_new(g_locale_to_utf8("SCORE:",-1,NULL,NULL,NULL));
    label2=gtk_label_new(g_locale_to_utf8("0",-1,NULL,NULL,NULL));
    gtk_label_set_markup(GTK_LABEL(label2),"<span font_desc='40'>0</span>");
    gtk_widget_set_size_request(draw_erea,320,640);//设置大小
    gtk_container_set_border_width(GTK_CONTAINER(window),40);
    gtk_container_add(GTK_CONTAINER(window),table);
    gtk_table_attach(GTK_TABLE(table),draw_erea,0,1,0,2,
        (GtkAttachOptions)(0),(GtkAttachOptions)(0),20,20);
    gtk_table_attach(GTK_TABLE(table),label1,1,2,0,1,
        (GtkAttachOptions)(0),(GtkAttachOptions)(0),20,20);
    gtk_table_attach(GTK_TABLE(table),label2,1,2,1,2,
        (GtkAttachOptions)(0),(GtkAttachOptions)(0),20,20);
 
    g_signal_connect(G_OBJECT(draw_erea),"expose_event",G_CALLBACK(expose_event_callback),NULL);//重绘事件
    g_signal_connect(G_OBJECT(window),"key-press-event",G_CALLBACK(key_value),NULL);
     
    gtk_entry_new();
    time_id=g_timeout_add(1000,(GtkFunction)timeout,NULL);
    gtk_widget_show_all(window);
    init();
    gtk_main();
    return (EXIT_SUCCESS);
}
