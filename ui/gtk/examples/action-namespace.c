/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:46 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:12 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:06:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:23 CST. */
#include <gtk/gtk.h>

static void
action_activated (GSimpleAction *action,
                  GVariant      *parameter,
                  gpointer       user_data)
{
  GtkWindow *parent = user_data;
  GtkWidget *dialog;

  dialog = gtk_message_dialog_new (parent,
                                   GTK_DIALOG_DESTROY_WITH_PARENT,
                                   GTK_MESSAGE_INFO,
                                   GTK_BUTTONS_CLOSE,
                                   "Activated action `%s`",
                                   g_action_get_name (G_ACTION (action)));

  g_signal_connect_swapped (dialog, "response",
                            G_CALLBACK (gtk_widget_destroy), dialog);

  gtk_widget_show_all (dialog);
}

static GActionEntry doc_entries[] = {
  { "save", action_activated },
  { "print", action_activated },
  { "share", action_activated }
};

static GActionEntry win_entries[] = {
  { "fullscreen", action_activated },
  { "close", action_activated },
};

const gchar *menu_ui =
  "<interface>"
  "  <menu id='doc-menu'>"
  "    <section>"
  "      <item>"
  "        <attribute name='label'>_Save</attribute>"
  "        <attribute name='action'>save</attribute>"
  "      </item>"
  "      <item>"
  "        <attribute name='label'>_Print</attribute>"
  "        <attribute name='action'>print</attribute>"
  "      </item>"
  "      <item>"
  "        <attribute name='label'>_Share</attribute>"
  "        <attribute name='action'>share</attribute>"
  "      </item>"
  "    </section>"
  "  </menu>"
  "  <menu id='win-menu'>"
  "    <section>"
  "      <item>"
  "        <attribute name='label'>_Fullscreen</attribute>"
  "        <attribute name='action'>fullscreen</attribute>"
  "      </item>"
  "      <item>"
  "        <attribute name='label'>_Close</attribute>"
  "        <attribute name='action'>close</attribute>"
  "      </item>"
  "    </section>"
  "  </menu>"
  "</interface>";

static void
activate (GApplication *app,
          gpointer      user_data)
{
  GtkWidget *win;
  GtkWidget *button;
  GSimpleActionGroup *doc_actions;
  GtkBuilder *builder;
  GMenuModel *doc_menu;
  GMenuModel *win_menu;
  GMenu *button_menu;
  GMenuItem *section;

  if (gtk_application_get_windows (GTK_APPLICATION (app)) != NULL)
    return;

  win = gtk_application_window_new (GTK_APPLICATION (app));
  gtk_window_set_default_size (GTK_WINDOW (win), 200, 300);

  doc_actions = g_simple_action_group_new ();
  g_action_map_add_action_entries (G_ACTION_MAP (doc_actions), doc_entries, G_N_ELEMENTS (doc_entries), win);

  g_action_map_add_action_entries (G_ACTION_MAP (win), win_entries,
                                   G_N_ELEMENTS (win_entries), win);

  builder = gtk_builder_new ();
  gtk_builder_add_from_string (builder, menu_ui, -1, NULL);

  doc_menu = G_MENU_MODEL (gtk_builder_get_object (builder, "doc-menu"));
  win_menu = G_MENU_MODEL (gtk_builder_get_object (builder, "win-menu"));

  button_menu = g_menu_new ();

  section = g_menu_item_new_section (NULL, doc_menu);
  g_menu_item_set_attribute (section, "action-namespace", "s", "doc");
  g_menu_append_item (button_menu, section);
  g_object_unref (section);

  section = g_menu_item_new_section (NULL, win_menu);
  g_menu_item_set_attribute (section, "action-namespace", "s", "win");
  g_menu_append_item (button_menu, section);
  g_object_unref (section);

  button = gtk_menu_button_new ();
  gtk_button_set_label (GTK_BUTTON (button), "Menu");
  gtk_widget_insert_action_group (button, "doc", G_ACTION_GROUP (doc_actions));
  gtk_menu_button_set_menu_model (GTK_MENU_BUTTON (button), G_MENU_MODEL (button_menu));
  gtk_widget_set_halign (GTK_WIDGET (button), GTK_ALIGN_CENTER);
  gtk_widget_set_valign (GTK_WIDGET (button), GTK_ALIGN_START);
  gtk_container_add (GTK_CONTAINER (win), button);
  gtk_container_set_border_width (GTK_CONTAINER (win), 12);
  gtk_widget_show_all (win);

  g_object_unref (button_menu);
  g_object_unref (doc_actions);
  g_object_unref (builder);
}

int
main(int    argc,
     char **argv)
{
  GtkApplication *app;

  app = gtk_application_new ("org.gtk.Example", 0);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

  return g_application_run (G_APPLICATION (app), argc, argv);
}
