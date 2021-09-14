/***********************************************************************
 * FILENAME:
 * keyboard.c
 *
 * DESCRIPTION:
 * Module to store keyboard signals to be emulated by xdotool 
 * library. Ini config files are loaded here.
 *
 * PUBLIC FUNCTIONS:
 * int load_ini(const char *filename)
 * char *get_axis_by_index(const uint8_t index, const unsigned int ordering)
 * char *get_button_by_index(const uint8_t index)
 *
 * AUTHOR:
 * Donald J Smith
 *
 * DATE:
 * 8.28.17
 *
 ***********************************************************************/


#include "ini.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


#define MAX_COMMAND_SIZE        32
#define MAX_AXIS                4
#define MAX_BUTTONS             16


static const char axis[MAX_COMMAND_SIZE][5] = {
    "axis0",
    "axis1",
    "axis2",
    "axis3"
};
static const char button[] = "button";


/* keyboard map datamap */
static char axis_command[MAX_AXIS][2][MAX_COMMAND_SIZE];
static bool axis_command_used[MAX_AXIS][2];
static char button_command[MAX_BUTTONS][MAX_COMMAND_SIZE];
static bool button_command_used[MAX_BUTTONS];

static int load_from_init(void *user, const char *section, const char *name, const char *value)
{
    int a;
    (void)(user);
    for (a = 0; a < MAX_AXIS; a++) {
        if (strncmp(section, axis[a], sizeof(axis[a])) == 0) {
            const uint8_t i = atoi(name);
            if (i < MAX_AXIS) {
                if (i < 2) {
                    strncpy(axis_command[a][i], value, MAX_COMMAND_SIZE);
                    axis_command_used[a][i] = true;
                }
            }
        }
    }
    if (strncmp(section, button, sizeof(button)) == 0) {
        const uint8_t i = atoi(name);
        if (i < MAX_BUTTONS) {
            strncpy(button_command[i], value, MAX_COMMAND_SIZE);
            button_command_used[i] = true;
        }
    }
    return 0;
}


char *get_button_by_index(const uint8_t index)
{
    if (index < MAX_BUTTONS)
        if (button_command_used[index])
            return button_command[index];
    return NULL;
}


char *get_axis_by_index(const uint8_t index, const unsigned int ordering)
{
    if (index < MAX_AXIS)
        if (ordering < 2)
            if (axis_command_used[index][ordering])
                return axis_command[index][ordering];
    return NULL;
}


static void reset_keyboard_map(void)
{
    int i;
    for (i = 0; i < MAX_AXIS; i++) {
        axis_command_used[i][0] = false;
        axis_command_used[i][1] = false;
    }
    for (i = 0; i < MAX_BUTTONS; i++)
        button_command_used[i] = false;
}


int load_ini(const char *filename)
{
    reset_keyboard_map();
    return ini_parse(filename, load_from_init, NULL) - 1;
}


