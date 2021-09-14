
/* interface to module joyevdev.c */

#ifndef JOYXDO_JOYEVDEV_H
#define JOYXDO_JOYEVDEV_H

bool init_joystick(void);
void print_joystick_info(void);
void get_joystick_info(void);
bool make_default_joystick_config(char *filename);
void kill_joystick(void);

#endif
