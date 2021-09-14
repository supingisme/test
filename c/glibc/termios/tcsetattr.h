#include <termios.h>
#include <unistd.h>


int tcsetattr(int fd, int optional_actions,
              const struct termios *termios_p);

