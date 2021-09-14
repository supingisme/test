#include <stdio.h>
#include <stdlib.h>
#include "tr069_cwmp_api.h"


int get_value_response(GetParameterValues *request, GetParameterValuesResponse **response)
{
    printf("TR069: GetParameterValues: %s\n", request->ParameterNames);

#if 0
    
#else
    
    (*response) = malloc(sizeof(GetParameterValuesResponse));

    sprintf((*response)->Parameter.Name, request->ParameterNames);
    sprintf((*response)->Parameter.Value, "RongtaoValueRT");

    

#endif

    return 0;
}


