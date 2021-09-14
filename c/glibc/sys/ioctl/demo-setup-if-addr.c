#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
//#include <netinet/if.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/if_tun.h>
#include <net/if.h>
#include <netinet/in.h>
#include <malloc.h>
#include <string.h>

/******************* This is copied from srsue gw **********************/
int setup_if_addr(char *ip_addr)
{

	char *dev = (char*) "tun_srsue";

	/* Construct the TUN device*/
	int tun_fd = open("/dev/net/tun", O_RDWR);
	if(0 > tun_fd)
	{
		perror("open");
		return(-1);
	}

	struct ifreq ifr;

	memset(&ifr, 0, sizeof(ifr));
	ifr.ifr_flags = IFF_TUN | IFF_NO_PI;
	strncpy(ifr.ifr_ifrn.ifrn_name, dev, IFNAMSIZ);
	if(0 > ioctl(tun_fd, TUNSETIFF, &ifr))
	{
		perror("ioctl");
		return -1;
	}

	/* Bring up the interface*/
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(0 > ioctl(sock, SIOCGIFFLAGS, &ifr))
	{
		perror("socket");
		return -1;
	}
	ifr.ifr_flags |= IFF_UP | IFF_RUNNING;
	if(0 > ioctl(sock, SIOCSIFFLAGS, &ifr))
	{
		perror("ioctl");
		return -1;
	}

	/* Setup the IP address    */
	sock                                                   = socket(AF_INET, SOCK_DGRAM, 0);
	ifr.ifr_addr.sa_family                                 = AF_INET;
	((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr.s_addr = inet_addr(ip_addr);
	if(0 > ioctl(sock, SIOCSIFADDR, &ifr))
	{
		perror("ioctl");
		return -1;
	}
	ifr.ifr_netmask.sa_family                                 = AF_INET;
	((struct sockaddr_in *)&ifr.ifr_netmask)->sin_addr.s_addr = inet_addr("255.255.255.0");
	if(0 > ioctl(sock, SIOCSIFNETMASK, &ifr))
	{
		perror("ioctl");
		return -1;
	}

	return(tun_fd);
}



int main()
{
	setup_if_addr("10.170.6.90");	
}



