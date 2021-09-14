/***********************************************************************
 * FILENAME:
 * mapper.c
 *
 * DESCRIPTION:
 * Module to map character strings passed from libevdev to the xdo library to
 * simulate keyboard input.
 *
 * PUBLIC FUNCTIONS:
 * bool init_mapper(void)
 * void kill_mapper(void)
 * void xdo_down(const char *key_string)
 * void xdo_up(const char *key_string)
 *
 * AUTHOR:
 * Donald J Smith
 *
 * DATE:
 * 6.12.17
 *
 ***********************************************************************/


/* standard c library headers, plus curses and xdo. */
#include <stdbool.h>
#include <stdio.h>
#include <curses.h>
#include <xdo.h>


/* xdo library context */
static xdo_t *xd = NULL;


/* -------------------------------*/
/**
 * @Synopsis  Use curses to show the character string -- used to show the
 * current mapped keysequence.
 *
 * @Param key_string Keys to print, as character string.
 */
/* ---------------------------------*/
static void show_keysequence(const char *key_string)
{
    mvprintw(LINES - 2, 0, "            ");
    mvprintw(LINES - 2, 0, "%s", key_string);
}


/* -------------------------------*/
/**
 * @Synopsis  Set up xdo library for mapping keys.
 *
 * @Returns   True, if xdo library is working properly.
 */
/* ---------------------------------*/
bool init_mapper(void)
{
    xd = xdo_new(NULL);
    if (!xd)
        return false;
    return true;
}


/* -------------------------------*/
/**
 * @Synopsis  Terminate xdo library, called on program exit.
 */
/* ---------------------------------*/
void kill_mapper(void)
{
    if (xd)
        xdo_free(xd);
}


/* -------------------------------*/
/**
 * @Synopsis  Simulate keys being pressed down, using xdo library.
 *
 * @Param key_string String to simulate, passed to xdo library.
 */
/* ---------------------------------*/
void xdo_down(const char *key_string)
{
    show_keysequence(key_string);
    xdo_send_keysequence_window_down(xd, CURRENTWINDOW, key_string, 0);
}


/* -------------------------------*/
/**
 * @Synopsis  Simulate keys being released, using xdo library.
 *
 * @Param key_string String to simulate, passed to xdo library.
 */
/* ---------------------------------*/
void xdo_up(const char *key_string)
{
    xdo_send_keysequence_window_up(xd, CURRENTWINDOW, key_string, 0);
}


