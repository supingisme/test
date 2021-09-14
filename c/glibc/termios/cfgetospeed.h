#include <termios.h>
#include <unistd.h>

speed_t cfgetospeed(const struct termios *termios_p);

