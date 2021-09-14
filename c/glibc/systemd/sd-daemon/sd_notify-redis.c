#include <stdio.h>
#include <systemd/sd-daemon.h>

#define HAVE_LIBSYSTEMD 1

int redisCommunicateSystemd(const char *sd_notify_msg) {
    const char *notify_socket = getenv("NOTIFY_SOCKET");
    if (!notify_socket) {
        printf("systemd supervision requested, but NOTIFY_SOCKET not found");
    }

    #ifdef HAVE_LIBSYSTEMD
    (void) sd_notify(0, sd_notify_msg);
    #else
    UNUSED(sd_notify_msg);
    #endif
    return 0;
}


int main()
{
	redisCommunicateSystemd("READY=1");
}
