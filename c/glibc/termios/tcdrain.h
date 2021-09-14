#include <termios.h>
#include <unistd.h>

////等待直到所有写入fd引用的对象的输出都被传输
int tcdrain(int fd);

