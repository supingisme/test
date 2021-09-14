#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

static int _r_n_adapter_write(int fd, char *buf, int len)
{
	if(fd == 1 || fd == 2)
		return write(fd, buf, len);
    int i, n=0;
    for(i=0;i<len;)
    {
        if(buf[i] == '\n')
        {
            if(buf[i+1] == '\r')
            {
                n += write(fd, &buf[i], 2);
                i+=2;
            }
            else
            {
                n += write(fd, &buf[i], 1);
                n += write(fd, "\r", 1);
                n += write(fd, &buf[i+1], 1);
                i+=2;
            }
        }
        else if(buf[i] == '\r')
        {
            if(buf[i+1] == '\n')
            {
                n += write(fd, &buf[i], 2);
                i+=2;
            }
            else
            {
                n += write(fd, &buf[i], 1);
                n += write(fd, "\n", 1);
                n += write(fd, &buf[i+1], 1);
                i+=2;
            }
        }
        else
        {
            n += write(fd, &buf[i], 1);
            i++;
        }
    }
    return n;
}

int main()
{
	char *buf = "rongtao\nrongtao\nrrrrrrr";
	int fd = open("/dev/pts/9", O_RDWR);
	_r_n_adapter_write(fd, buf, strlen(buf));
	_r_n_adapter_write(1, buf, strlen(buf));
	return 0;
}
