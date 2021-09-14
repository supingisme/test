#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <sys/select.h>

#define INT32   int
#define CONST   const
#define CHAR    char


#define Popen   popen
#define Sprintf sprintf
#define Fgets   fgets
#define Memset  memset
#define Fclose  fclose
#define Strlen  strlen
#define Select  select

#define VCM_ERR (-1)
#define VCM_OK  (0)

#define log_vcm_info(fmt...)    printf(fmt)
#define log_vcm_debug()
#define log_vcm_succ(fmt...)    printf(fmt)


INT32 ipv4_is_not_conflict(CONST CHAR *ip_str)
{
    log_vcm_debug();
    
    if(ip_str == NULL || Strlen(ip_str) < 7)
	{
		return VCM_ERR;
	}

	char cmd[64] = {0};
	char line[256] = {0};

	Sprintf(cmd, "ping -w 1 -c 1 %s", ip_str);

	FILE *fpping = Popen(cmd, "r");
	int fdping = fileno(fpping);
    fd_set  pingfdset;
    FD_ZERO(&pingfdset);
    FD_SET(fdping, &pingfdset);
    
    
	/**
	 *	64 bytes from 10.170.6.62: icmp_seq=1 ttl=64 time=0.649 ms
	 */
	int bytes;
	int u1,u2,u3,u4;
	int icmp_seq;
	int ttl;
	float time;
	int countc;

	typedef enum {FREE_TO_USE = 1, CANT_USE}Useful_t;

	Useful_t Useful = FREE_TO_USE;

	while(Fgets(line, 256, fpping))
    //while(read(fdping, line, 256))
	{
	    /* can't use vos_sscanf, it's return wrong. */
		countc = sscanf(line, "%d bytes from %d.%d.%d.%d: icmp_seq=%d ttl=%d time=%f ms", 
						&bytes, &u1, &u2, &u3, &u4, &icmp_seq, &ttl, &time);
		
		Memset(line, 0, 256);
        
#define _VOS_SSCANF_RET(glibc_sscanf_ret)  (glibc_sscanf_ret+1)        

		if(countc == 8)
		{
            log_vcm_info("%d bytes from %d.%d.%d.%d: icmp_seq=%d ttl=%d time=%f\n", 
				        bytes, u1, u2, u3, u4, icmp_seq, ttl, time);
                        
			Useful = CANT_USE;
			break;
		}
        countc = 0;
	}

    INT32 ret = VCM_ERR;
    
	switch(Useful)
	{
		case CANT_USE:
			//printf("You can't use this IP address: %s\n", ip);
			ret = VCM_ERR;
			break;
		case FREE_TO_USE:
			//printf("You can use this IP address: %s\n", ip);
			ret = VCM_OK;
			break;
		default:
			ret = VCM_ERR;
			break;
	}
    Fclose(fpping);
	return ret;
}


int main(int argc, char *argv[])
{

	int u1,u2,u3,u4;
	char ip[16] = {0};

	u1 = 10;
	u2 = 170;
	for(u3=6;u3<8;u3+=1)
	{
		for(u4=1;u4<99;u4+=1)
		{
			memset(ip, 0, 16);
			sprintf(ip, "%d.%d.%d.%d", u1, u2, u3, u4);
			if(0 == ipv4_is_not_conflict(ip))
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