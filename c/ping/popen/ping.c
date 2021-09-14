/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:39 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int my_ping(char *ip);

int main(int argc, char *argv[])
{

	int u1,u2,u3,u4;
	char ip[16] = {0};

	u1 = 10;
	u2 = 170;
	for(u3=6;u3<17;u3++)
	{
		for(u4=35;u4<120;u4++)
		{
			memset(ip, 0, 16);
			sprintf(ip, "%d.%d.%d.%d", u1, u2, u3, u4);
			if(0 == my_ping(ip))
			{
				printf("%s can use.\n", ip);
			}
			else
			{
				printf("%s can't use.\n", ip);
			}
		}
	}


	return 0;
}

int my_ping(char *ip)
{
	if(ip == NULL || strlen(ip) < 7)
	{
		return -1;
	}

	char cmd[64] = {0};
	char line[256] = {0};

	sprintf(cmd, "ping -w 1 -c 1 %s", ip);

	FILE *fpping = popen(cmd, "r");
	printf("FD = %d\n", fileno(fpping));
	/**
	 *	64 bytes from 10.170.6.62: icmp_seq=1 ttl=64 time=0.649 ms
	 */
	int bytes;
	int u1,u2,u3,u4;
	int icmp_seq;
	int ttl;
	float time;
	int countc;

	typedef enum {CAN_USE = 1, CANT_USE}Useful_t;

	Useful_t Useful = CAN_USE;

	while(fgets(line, 256, fpping))
	{
		countc = sscanf(line, "%d bytes from %d.%d.%d.%d: icmp_seq=%d ttl=%d time=%f ms", 
						&bytes, &u1, &u2, &u3, &u4, &icmp_seq, &ttl, &time);
		//printf("My PING ->countc=%d, bytes = %d, ipaddr = %d.%d.%d.%d, icmp_seq=%d, ttl=%d, time=%f\n", 
		//		countc, bytes, u1, u2, u3, u4, icmp_seq, ttl, time);
		memset(line, 0, 256);
		//printf("countc = %d\n", countc);
		if(countc == 8)
		{
			Useful = CANT_USE;
			fclose(fpping);
			break;
		}
	}

	switch(Useful)
	{
		case CANT_USE:
			//printf("You can't use this IP address: %s\n", ip);
			return -1;
			break;
		case CAN_USE:
			//printf("You can use this IP address: %s\n", ip);
			fclose(fpping);
			return 0;
			break;
		default:
			break;
	}

	return -1;
}
