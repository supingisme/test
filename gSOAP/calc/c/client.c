#include "soapH.h"
#include "calc.nsmap"

int main()
{
    struct soap *soap = soap_new();
    double result;
    if (soap_call_ns__add(soap, 1.0, 2.0, &result) == SOAP_OK)
        printf("The sum of 1.0 and 2.0 is %lg\n", result);
    else
        soap_print_fault(soap, stderr);
    soap_end(soap);
    soap_free(soap);
}


