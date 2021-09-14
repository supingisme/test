#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <errno.h>
#include <sys/inotify.h>

static void _inotify_event_handler(struct inotify_event *event)
{

    printf("event->wd:      %d\n", event->wd);
    printf("event->mask:    0x%08x\n", event->mask);
    printf("event->cookie:  0x%08x\n", event->cookie);
    printf("event->len:     %d\n", event->len);

    printf("event->name:    %s\n", event->name);
}

int main(int argc, char *argv[])
{
    if(argc!=2){
        printf("%s [filename]\n",argv[0]);
        return -1;
    }
    unsigned char buf[1024] = {0};

    struct inotify_event *event = NULL;

    int fd = inotify_init();

    int wd = inotify_add_watch(fd, argv[1], IN_ALL_EVENTS);

    for(;;) {
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(fd, &fds);

        if(select(fd + 1, &fds, NULL, NULL, NULL) > 0) {
            int len, index =0;

            while(((len = read(fd, &buf, sizeof(buf))) > 0) && errno != EINTR/*读取到事件*/) {
                while(index < len) { 
                    event = (struct inotify_event *)(buf+index);
                    _inotify_event_handler(event);
                    index += sizeof(struct inotify_event) + event->len;
                }
            }
        }
        inotify_rm_watch(fd, wd);
        return 0;
    }
}
