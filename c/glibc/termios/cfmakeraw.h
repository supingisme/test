#include <termios.h>
#include <unistd.h>

void cfmakeraw(struct termios *termios_p);

//Raw mode
//cfmakeraw()  sets  the  terminal  to  something like the "raw" mode of the old Version 7 terminal driver:
//input is available character by character, echoing is disabled, and all special  processing  of  terminal
//input and output characters is disabled.  The terminal attributes are set as follows:
//
//    termios_p->c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
//                    | INLCR | IGNCR | ICRNL | IXON);
//    termios_p->c_oflag &= ~OPOST;
//    termios_p->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
//    termios_p->c_cflag &= ~(CSIZE | PARENB);
//    termios_p->c_cflag |= CS8;


