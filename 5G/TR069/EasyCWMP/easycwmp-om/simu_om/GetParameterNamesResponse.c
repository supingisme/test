#include <stdio.h>
#include <stdlib.h>
#include "tr069_cwmp_api.h"


int get_name_response(GetParameterNames *request, GetParameterNamesResponse **response)
{
    printf("TR069: GetParameterNames: %s:%d\n", request->ParameterPath, request->NextLevel);

#if 0
    
#else
    
    unsigned int ParameterNum=4;

    (*response) = malloc(sizeof(GetParameterNamesResponse)+ParameterNum*sizeof(ParameterInfoStruct));

    (*response)->ParameterNum = ParameterNum;

    sprintf((*response)->ParameterList[0].Name, "Device.RRU.%d.RRUID", 1);
    (*response)->ParameterList[0].Writable = 0;
    sprintf((*response)->ParameterList[1].Name, "Device.RRU.%d.RRUID", 2);
    (*response)->ParameterList[1].Writable = 0;

    
    sprintf((*response)->ParameterList[2].Name, "Device.FPGA.%d.FPGAID", 1);
    (*response)->ParameterList[2].Writable = 0;
    sprintf((*response)->ParameterList[3].Name, "Device.FPGA.%d.FPGAID", 2);
    (*response)->ParameterList[3].Writable = 0;
    

#endif

    return 0;
}

