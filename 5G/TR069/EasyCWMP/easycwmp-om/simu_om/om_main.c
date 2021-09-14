#include <stdio.h>
#include <stdlib.h>
#include "tr069_cwmp_api.h"

int get_name_response(GetParameterNames *request, GetParameterNamesResponse **response);

int get_value_response(GetParameterValues *request, GetParameterValuesResponse **response);


int main()
{
#if 1
    tr069_register_GetParameterNames(get_name_response);
    tr069_register_GetParameterValues(get_value_response);

    tr069_cwmp_init();
    
#else    

    tr069_oid_init();
    tr069_oid_register("Devide.ACC.FPGA.FEC.FPGAID", NULL,NULL,NULL,NULL);
    printf("\n");
    
    tr069_oid_register("Devide.ACC.FPGA.FEC.FPGAFAN", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Devide.ACC.FPGA.FEC.TEMP", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Devide.ACC.FPGA.FEC.FPGAFAN.TEMP", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Devide.ACC.FPGA.FH.FPGAID", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Devide.ACC.FPGA.FH_FEC.FPGAID", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Devide.ACC.FPGA.", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Devide.ACC.FPGA", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Devide.ACC.FPGA.FH_FEC.FPGAFAN", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Devide.RRU.1.RRUID", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Devide.RRU.1.RRUSN", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Devide.RRU.2.RRUID", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Devide.RRU.2.RRUSN", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Object.cell.1.cellid", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Object.cell.2.cellid", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Object.cell.3.cellid", NULL,NULL,NULL,NULL);
    printf("\n");
    tr069_oid_register("Object.cell.3.cellid", NULL,NULL,NULL,NULL);
    printf("\n");
//    tr069_oid_register("Object.cell.3", NULL,NULL,NULL,NULL);
//    printf("\n");
//    tr069_oid_register("Object.cell.3.cellid.globalID", NULL,NULL,NULL,NULL);
//    printf("\n");


    tr069_oid_display();
    tr069_oid_destroy();
    
#endif

    return 0;
}
