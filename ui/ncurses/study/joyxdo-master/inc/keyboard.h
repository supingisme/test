
/* interface to module keyboard.c */

#ifndef JOYXDO_KEYBOARD_H
#define JOYXDO_KEYBOARD_H

#include <stdint.h>

char *get_button_by_index(const uint8_t index);
char *get_axis_by_index(const uint8_t index, const unsigned int ordering);
int load_ini(const char *filename);


#endif
