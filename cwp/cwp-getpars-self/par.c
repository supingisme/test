#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdint.h>
#include <unistd.h>

#include "getpars.h"


static const char* sdoc[] = {
"   ",
"CELL_MGMT  ",
"   cell management module console",
"   ",
"\033[1;31mDESCRIPTION\033[0m",
"   This is a console command, that is to make some right.",
"   ",
"\033[1;31mPARAMETER\033[0m",
"   src=    source module address",
"           1 - CELL_MGMT",
"           2 - BORD_MGMT",
"   dst=    destination module address",
"           3 - RRUS_MGMT",
"           4 - ALAM_MGMT",
"   parfile=    input file parameters",
"   ",
"\033[1;31mWARNING\033[0m: If not define parfile, you must define the following parameters ",
"   msgcode = message code of messages ",
"             1 - cell setup message",
"             2 - cell delete message",
"   cell_id = cell global id ",
"             veritual cell: 1, 2, 3, ..., 8",
"             simulate cell: 8, 9, 10, ..., 17",
"   ",
"\033[1;31mExample\033[0m",
"   cell_mgmt src=1 dst=1 parfile=par.txt",
"   ",
"\033[1mVersion 1.0.0 Copyright@Sylincom 2019\033[0m",
"   ",
NULL,
};


int main(int argc, char *argv[])
{
    /* initialize */
    args_init(argc, argv, 1, sdoc);
    
    /* get parameters */
    uint16_t src = 1;      getparuint("src",&src, MUST_HAVE);
    uint16_t dst = 1;      getparuint("dst",&dst, MUST_HAVE);

    char *parfile;         getparstring("parfile", &parfile, MUST_HAVE);
    uint32_t cell_id = 1;  getparuint("cell_id",&cell_id, MUST_HAVE);
    
    printf("src = %d, dst = %d, parfile = %s, cell_id = %d\n", src, dst, parfile, cell_id);

    return 0;
}
