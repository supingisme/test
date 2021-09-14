#include <termios.h>
#include <unistd.h>

int cfsetospeed(struct termios *termios_p, speed_t speed);

