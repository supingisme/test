/**
 *  TR-181: Device Data Model for TR-069
 *      Rong Tao 
 */
#ifndef __TR181_H
#define __TR181_H 1


struct dateTime {//TODO
    unsigned long data;//yyyy-mm-ddThh:mm:ss
};

struct dev_FAP_perfmgmt_cfg {
    bool enable;
    char alias[64];
    char URL[256];
    char username[256];
    char passwd[256];
    unsigned int prioULinterval; //1-65535
    struct dateTime prioULtime;//yyyy-mm-ddThh:mm:ss
};




#endif /*<__TR181_H>*/
