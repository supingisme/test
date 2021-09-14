#include <stdio.h>
#include <stdlib.h>
#include "soapStub.h"
#include "SmsWBS.nsmap"

int add(const char *server, int num1, int num2, int *sum);

int add(const char *server, int num1, int num2, int *sum)
{
        struct soap SmsWBS_soap;
        int result = 0;

        soap_init(&SmsWBS_soap);
        soap_set_namespaces(&SmsWBS_soap, namespaces);

        soap_call_ns__add(&SmsWBS_soap, server, "", num1, num2, sum);

        if(SmsWBS_soap.error)
        {
                printf("soap error:%d, %s, %s ", SmsWBS_soap.error, *soap_faultcode(&SmsWBS_soap), *soap_faultstring(&SmsWBS_soap));
                result = SmsWBS_soap.error;
         }

        soap_end(&SmsWBS_soap);
        soap_done(&SmsWBS_soap);

        return result;
}

int main(int argc, char **argv)
{
        int result = -1;
        char* server="http://localhost:9000";

        int num1 = 0;
        int num2 = 0;
        int sum = 0;

        if( argc < 3 )
        {
                printf("usage: %s num1 num2 \n", argv[0]);
                exit(0);

        }

        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);

        result = add(server, num1, num2, &sum);
        if (result != 0)
        {
                printf("soap err, errcode = %d \n", result);
        }
        else
        {
                printf("%d + %d = %d \n", num1, num2, sum);
        }

        return 0;
}
