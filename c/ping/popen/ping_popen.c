#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <fcntl.h>
#include <string.h>

#define INT32   int
#define CONST   const
#define CHAR    char


#define Popen   popen
#define Sprintf sprintf
#define Fgets   fgets
#define Memset  memset
#define Fclose  fclose
#define Strlen  strlen


#define VCM_ERR (-1)
#define VCM_OK  (0)

#define log_vcm_info(fmt...)
#define log_vcm_debug()
#define log_vcm_succ(fmt...)


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
#if 0
//	fcntl(fileno(fpping), );
	/**
	 * *  NON block file descriptor set, make Read msg bolck
	 * */
	int retu = -1;
	int flags = fcntl(fileno(fpping), F_GETFL);
	if(flags == -1)
	{
		//log_vcm_err("Fcntl error. F_GETFL\n");
		return VCM_ERR;
	}
	flags = flags | O_NONBLOCK;
	retu = fcntl(fileno(fpping), F_SETFL, flags);
	if(retu == -1)
	{
		//log_vcm_err("Fcntl error. F_SETFL\n");
		//__vcm_set_errno(_VCM_EFDSETBLOCKERR);
		return VCM_ERR;
	}
#endif
	while(Fgets(line, 256, fpping))
	{
	    /* can't use vos_sscanf, it's return wrong. */
		countc = sscanf(line, "%d bytes from %d.%d.%d.%d: icmp_seq=%d ttl=%d time=%f ms", 
						&bytes, &u1, &u2, &u3, &u4, &icmp_seq, &ttl, &time);
		log_vcm_info("My PING ->countc=%d, bytes = %d, ipaddr = %d.%d.%d.%d, icmp_seq=%d, ttl=%d, time=%f\n", 
				        countc, bytes, u1, u2, u3, u4, icmp_seq, ttl, time);
		Memset(line, 0, 256);
        //log_vcm_alarm("countc = %d\n", countc);
        
#define _VOS_SSCANF_RET(glibc_sscanf_ret)  (glibc_sscanf_ret+1)        

		if(countc == 8)
		{
		    log_vcm_succ("Ping %s is OK.\n", ip_str);
			Useful = CANT_USE;
			Fclose(fpping);
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
			Fclose(fpping);
			ret = VCM_OK;
			break;
		default:
			ret = VCM_ERR;
			break;
	}

	return ret;
}


int main(int argc, char *argv[])
{

	int u1,u2,u3,u4;
	char ip[16] = {0};

	u1 = 10;
	u2 = 170;
	for(u3=7;u3<17;u3++)
	{
		for(u4=35;u4<120;u4++)
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
