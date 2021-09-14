#include <termios.h>
#include <unistd.h>

int cfsetspeed(struct termios *termios_p, speed_t speed);

