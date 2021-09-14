#ifndef __COM_H
#define __COM_H

#define MAXLINE 1024

#define PORT_CN 2152

#define PORT_DU 2153

#define PORT_CUUP_CN PORT_CN
#define PORT_CUUP_DU PORT_DU

#define ADDR_CN		"10.170.7.166"
#define ADDR_CUUP	"10.170.7.169"
#define ADDR_DU		"10.170.7.170"


struct message {
#define MAGIC_CN    0x12345678
#define MAGIC_CN    0x12345678
    int magic_number;
    
};


#endif

