#include "common_func.h"
#include "window_main.h"


GtkWidget *create_main_window()
{//创建主窗口
    GtkWidget *window;
    GtkWidget *vbox;            //盒装容器
    GtkWidget *menubar;         //菜单栏
    GtkWidget *menutoggle, *menu_tog_toggle,*menu_tog_toolbar, *menu_tog_statusbar;  //界面开关菜单
    //GtkWidget *menu_about, *menu_about_us;  //帮助菜单
    GtkWidget *toolbar;         //工具栏
    GtkToolItem *tool_exit, *tool_sep,*tool_about;
    GtkWidget *statusbar;       //状态栏


    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "一步一步学GTK+ DEMO");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 400);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    /*函数gtk_window_set_icon() 是为窗口设置图标用的，函数create_pixbuf是我们自定义的，目的是从一个图片中获取信息得到pixbuf。*/
    gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("./gtk.png"));

    /*创建一个盒装容器并添加到窗口中*/
    vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    /*创建菜单*/
    menubar = gtk_menu_bar_new();   //代表整个菜单,是一个menu shell

    menutoggle = gtk_menu_new();   //这里代表第一列菜单toggle ,也是一个menu shell
    menu_tog_toggle = gtk_menu_item_new_with_label("View");

    menu_tog_toolbar = gtk_check_menu_item_new_with_label("show Toolbar");
    gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu_tog_toolbar),TRUE);
    menu_tog_statusbar = gtk_check_menu_item_new_with_label("show Statusbar");
    gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu_tog_statusbar),TRUE);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_tog_toggle), menutoggle);  //widget toggle菜单加入 menutoggle menu shell
    gtk_menu_shell_append(GTK_MENU_SHELL(menutoggle), menu_tog_toolbar);
    gtk_menu_shell_append(GTK_MENU_SHELL(menutoggle), menu_tog_statusbar);


    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu_tog_toggle);


    //创建工具栏
    toolbar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS); //设置工具栏样式为图标
    gtk_container_set_border_width(GTK_CONTAINER(toolbar), 0);      //工具栏边框大小

    tool_exit = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);     //工具栏中的 “退出” 按钮
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), tool_exit, -1);

    tool_sep = gtk_separator_tool_item_new();                       //工具栏中按钮之间的分割线
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), tool_sep, -1);

    tool_about = gtk_tool_button_new_from_stock(GTK_STOCK_HELP);    //工具栏中的“关于” 按钮
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), tool_about, -1);


    statusbar = gtk_statusbar_new();
    /*把菜单加入盒子容器*/
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 1);
    /*把工具栏加入盒子容器*/
    gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 0);
    /*把状态栏加入盒子最下面*/
    gtk_box_pack_end(GTK_BOX(vbox), statusbar, FALSE, TRUE, 1);

     /***********************************以下是信号处理部分************************************/
    /*关闭窗口时退出主循环*/
    g_signal_connect_swapped(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(tool_exit), "clicked",G_CALLBACK(gtk_main_quit), NULL);

    g_signal_connect(G_OBJECT(menu_tog_toolbar), "activate",G_CALLBACK(toggle_display), toolbar);
    g_signal_connect(G_OBJECT(menu_tog_statusbar), "activate",G_CALLBACK(toggle_display), statusbar);

    /***********************************以下是显示控件部分************************************/
    /*开始显示窗口*/
    //gtk_widget_show_all(window);

    //gtk_main();
    //return 0;
    return window;

}
