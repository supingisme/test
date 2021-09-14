/***********************************************************************
 * FILENAME:
 * joyevdev.c
 *
 * DESCRIPTION:
 * Module to get latest event polling from gamepad or joystick
 * via standard libevdev. We also interface with ncurses here
 * so user knows what's going on.
 *
 * PUBLIC FUNCTIONS:
 * void get_joystick_info(void)
 * bool make_default_joystick_config(char *filename)
 * void print_joystick_info(void)
 * bool init_joystick(void)
 * void kill_joystick(void)
 *
 * AUTHOR:
 * Donald J Smith
 *
 * DATE:
 * 8.28.17
 *
 ***********************************************************************/


#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <libevdev/libevdev.h>
#include <dirent.h>

#include "keyboard.h"
#include "mapper.h"


/* Much of this code I wrote after reading Megh Parikh's blog post
 * https://meghprkh.github.io/blog/2016/06/03/Handling-joysticks-and-gamepads-in-linux/
 * very helpful! Though after rewriting this utility this code now bears little resemblance
 * to what he posted. Be sure to check out his gamepad libary for vala at:
 * https://github.com/meghprkh/libgamepad
 */


/* Few joysticks will have more than 26 buttons...
 */
#define MAX_DEFAULT_BUTTONS         26

/* when generating a profile, use this button ordering by default.
 */
const char button_defaults[] = "qwertyuiopasdfghjklzxcvbnm";

/* size of string describing path to device --
 * 256 is probably enough, much less 512 bytes!
 * note that char is used, as utf-8 is the Linux
 * defacto standard.
 */
#define PATH_SIZE                   512

/* my favorite macro, based on Zed Shaw's famous debug
 * error check
 */
#define check(x)    if(!(x)) goto error


/* datamap for local gamepad libray */
static DIR *device_directory = NULL;
static int axis_count = 0;
static int buttons_count = 0;
static int hats_count = 0;
static struct dirent *device_entry = NULL;
static struct libevdev *input_device = NULL;
static uint8_t abs_map[ABS_MAX];
static uint8_t key_map[KEY_MAX];


/* epsilon values for centering. works on all the joysticks I have. */
static const unsigned int lower_epsilon = 100;
static const unsigned int upper_epsilon = 200;


static bool centered(const unsigned int value)
{
    /* determine if axis or hat is centered. */
    if (value > lower_epsilon && value < upper_epsilon)
        return true;
    return false;
}


static void button_held_down(const uint8_t button_index)
{
    /* tell mapper that given button at index is down */
    const char *command = get_button_by_index(button_index);
    if (command)
        xdo_down(command);
}


static void button_released(const uint8_t button_index)
{
    /* tell mapper that given button at index is released */
    const char *command = get_button_by_index(button_index);
    if (command)
        xdo_up(command);
}


static void axis_held_down(const uint8_t axis_index, const unsigned int value)
{
    /* tell our mapper that axis is held at position "value."
     */
    const char *lower_command = get_axis_by_index(axis_index, 0);
    const char *upper_command = get_axis_by_index(axis_index, 1);
    if (value < lower_epsilon) {
        if (lower_command)
            xdo_down(lower_command);
        if (upper_command)
            xdo_up(upper_command);
    }
    if (value > upper_epsilon) {
        if (upper_command)
            xdo_down(upper_command);
        if (lower_command)
            xdo_up(lower_command);
    }
}


static void axis_centered(const uint8_t axis_index)
{
    /* tell our mapper that axis at index is centered according to joystick.
     */
    const char *lower_command = get_axis_by_index(axis_index, 0);
    const char *upper_command = get_axis_by_index(axis_index, 1);
    if (lower_command)
        xdo_up(lower_command);
    if (upper_command)
        xdo_up(upper_command);
}



static void interpret_button(const uint8_t button_index, const bool value)
{
    /* tell our mapper function that a given joystick button is either held or
     * released.
     */
    if (value) {
        button_held_down(button_index);
    } else {
        button_released(button_index);
    }
}


static bool find_joystick_event_queue(const char *path)
{
    /* specialized string search to find the label "event-joystick" at
     * program load.
     */
    const char label[] = "event-joystick";
    const int length_a = strlen(path);
    const int length_b = strlen(label);
    int a, b;
    if (length_a < length_b)
        return false;
    a = length_a - 1;
    for (b = length_b; b--; ) {
        if (label[b] != path[a])
            return false;
        a--;
    }
    return true;
}



/**
 * @Synopsis Terminate joystick stuff in memory. Called at program exit.
 */
void kill_joystick(void)
{
    if (device_directory)
        closedir(device_directory);
    if (input_device)
        libevdev_free(input_device);
}


static bool get_joystick_device_path(char *path, const size_t path_size)
{
    /* set device path for joystick, using modern safe c string functions
     *  note that as a consequence of this, the path cannot exceed "path_size"
     *  set above
     */
    const char *libevdev_path = "/dev/input/by-path/";
    if ((device_directory = opendir(libevdev_path)) != NULL) {
        while ((device_entry = readdir(device_directory)) != NULL)
            if (find_joystick_event_queue(device_entry->d_name))
                break;
        check(device_entry);
        snprintf(path, path_size, "%s%s", libevdev_path, device_entry->d_name);
        return true;
    }
error:
    return false;
}


/**
 * @Synopsis Initailize joystick device path. Called once, at program start.
 *
 * @Returns True on successful load.
 */
bool init_joystick(void)
{
    /* flag with error if anything goes wrong -- usually joystick simply isn't
     * plugged in. */
    int fd;
    int rc = 1;
    char path[PATH_SIZE];
    check(get_joystick_device_path(path, PATH_SIZE));
    fd = open(path, O_RDONLY|O_NONBLOCK);
    rc = libevdev_new_from_fd(fd, &input_device);
    check(rc >= 0);
    return true;
error:
    fprintf(stderr, "Failed to init libevdev (%s)\n", strerror(-rc));
    kill_joystick();
    return false;
}


static void buttons_report(void)
{
    /* print data on joystick buttons to screen. */
    int i;
    for (i = BTN_JOYSTICK; i < KEY_MAX; ++i) {
        if (libevdev_has_event_code(input_device, EV_KEY, i)) {
            printw("%d - Joystick has button: 0x%x - %s\n", buttons_count, i,
                    libevdev_event_code_get_name(EV_KEY, i));
            key_map[i - BTN_MISC] = buttons_count;
            ++buttons_count;
        }
    }
    for (i = BTN_MISC; i < BTN_JOYSTICK; ++i) {
        if (libevdev_has_event_code(input_device, EV_KEY, i)) {
            printw("%d - Joystick has button: 0x%x - %s\n", buttons_count, i,
                    libevdev_event_code_get_name(EV_KEY, i));
            key_map[i - BTN_MISC] = buttons_count;
            ++buttons_count;
        }
    }
}


static void axis_report(void)
{
    /* print data on joystick axis to screen. */
    int i;
    for (i = 0; i < ABS_MAX; ++i) {
        if (i == ABS_HAT0X) {
            i = ABS_HAT3Y;
            continue;
        }
        if (libevdev_has_event_code(input_device, EV_ABS, i)) {
            const struct input_absinfo *absinfo = libevdev_get_abs_info(input_device, i);
            printw("Joystick has absolute axis: 0x%.2x - %s, %d\n", i, libevdev_event_code_get_name(EV_ABS, i), i);
            printw("Values = { %d, %d, %d, %d, %d }\n",
                    absinfo->value, absinfo->minimum, absinfo->maximum,
                    absinfo->fuzz, absinfo->flat);
            abs_map[i] = axis_count;
            ++axis_count;
        }
    }
}


static void hats_report(void)
{
    /* print data on joystick hat positions to screen. */
    int i;
    for (i = ABS_HAT0X; i <= ABS_HAT3Y; i += 2) {
        if (libevdev_has_event_code(input_device, EV_ABS, i) || libevdev_has_event_code(input_device, EV_ABS, i+1)) {
            const struct input_absinfo *absinfo = libevdev_get_abs_info(input_device, i);
            if (absinfo == NULL)
                continue;
            printw("Joystick has hat %d\n", (i - ABS_HAT0X) / 2);
            printw("Values = { %d, %d, %d, %d, %d }\n",
                    absinfo->value, absinfo->minimum, absinfo->maximum,
                    absinfo->fuzz, absinfo->flat);
            ++hats_count;
        }
    }
}


/**
 * @Synopsis Report current joystick status to user.
 */
void print_joystick_info(void)
{
    printw("Gamepad device name: \"%s\"\n", libevdev_get_name(input_device));
    printw("Gamepad device ID: bus %#x vendor %#x product %#x\n",
            libevdev_get_id_bustype(input_device),
            libevdev_get_id_vendor(input_device),
            libevdev_get_id_product(input_device));
    printw("Press ESCAPE to exit\n");
    buttons_report();
    axis_report();
    hats_report();
    refresh();
}


/**
 * @Synopsis When no configuration for a profile can be found, auto-generate
 * one and exit program.
 *
 * @Param filename Name of profile to generate.
 *
 * @Return True, on successful profile write.
 */
bool make_default_joystick_config(char *filename)
{
    FILE *f = fopen(filename, "w");
    int i;
    int count = 0;
    if (!f) {
        fprintf(stderr, "Error opening file for write: %s\n", filename);
        return false;
    }
    fprintf(f, "; auto generated config for %s\n", filename);
    fprintf(f, "\n\n; buttons\n[button]\n");
    for (i = BTN_JOYSTICK; i < KEY_MAX; ++i) {
        if (libevdev_has_event_code(input_device, EV_KEY, i)) {
            char c = 'q';
            if (count < MAX_DEFAULT_BUTTONS)
                c = button_defaults[count];
            fprintf(f, "%d=%c\n", count, c);
            ++count;
        }
    }
    for (i = BTN_MISC; i < BTN_JOYSTICK; ++i) {
        if (libevdev_has_event_code(input_device, EV_KEY, i)) {
            char c = 'q';
            if (count < MAX_DEFAULT_BUTTONS)
                c = button_defaults[count];
            fprintf(f, "%d=%c\n", count, c);
            ++count;
        }
    }
    fprintf(f, "\n\n; axis\n");
    count = 0;
    for (i = 0; i < ABS_MAX; ++i) {
        if (i == ABS_HAT0X) {
            i = ABS_HAT3Y;
            continue;
        }
        if (libevdev_has_event_code(input_device, EV_ABS, i)) {
            char *direction0 = "lower";
            char *direction1 = "upper";
            fprintf(f, "; %s\n", libevdev_event_code_get_name(EV_ABS, i));
            if (strcmp(libevdev_event_code_get_name(EV_ABS, i), "ABS_X") == 0) {
                direction0 = "Left";
                direction1 = "Right";
            }
            if (strcmp(libevdev_event_code_get_name(EV_ABS, i), "ABS_Y") == 0) {
                direction0 = "Up";
                direction1 = "Down";
            }
            fprintf(f, "[axis%d]\n", count);
            fprintf(f, "0=%s\n", direction0);
            fprintf(f, "1=%s\n\n", direction1);
            count++;
        }
    }
    fclose(f);
    return true;
}


/**
 * @Synopsis Get current joystick data from libevdev.
 */
void get_joystick_info(void)
{
    int rc;
    struct input_event ev;
    const unsigned int print_row = LINES - 1;
    float v;
    rc = libevdev_next_event(input_device, LIBEVDEV_READ_FLAG_NORMAL, &ev);
    if (rc == 0) {
        switch (ev.type) {
            case EV_KEY:
                if (ev.code >= BTN_MISC) {
                    mvprintw(print_row, 0, "Button %d, %d\n", key_map[ev.code - BTN_MISC], ev.value);
                    interpret_button(key_map[ev.code - BTN_MISC], ev.value);
                    refresh();
                }
                return;
            case EV_ABS:
                switch (ev.code) {
                    case ABS_HAT0X:
                    case ABS_HAT0Y:
                    case ABS_HAT1X:
                    case ABS_HAT1Y:
                    case ABS_HAT2X:
                    case ABS_HAT2Y:
                    case ABS_HAT3X:
                    case ABS_HAT3Y:
                        ev.code -= ABS_HAT0X;
                        mvprintw(print_row, 0, "Hat %d Axis %d Value %d\n", ev.code / 2, ev.code % 2, ev.value);
                        refresh();
                        break;
                    default:
                        v = ((float)ev.value) / 255;
                        mvprintw(print_row, 0, "Axis %d Value %.1f\n", abs_map[ev.code], v);
                        refresh();
                        if (centered(ev.value))
                            axis_centered(abs_map[ev.code]);
                        else
                            axis_held_down(abs_map[ev.code], ev.value);
                        break;
                }
                break;
            case EV_REL:
                switch (ev.code) {
                    case REL_X:
                    case REL_Y:
                        ev.code -= REL_X;
                        mvprintw(print_row, 0, "Ball %d Axis %d Value %d\n", ev.code / 2, ev.code % 2, ev.value);
                        refresh();
                        break;
                    default:
                        break;
                }
                break;
        }
    }
}


