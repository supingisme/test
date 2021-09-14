#include "soapProxy.h"
#include "ns.nsmap"

char server[256] = "http://127.0.0.1:";

int main(int argc, char **argv)
{ 
    time_t result;


    Proxy calc;
    strcat(server, "8080");
    calc.soap_endpoint = server;

    calc.currentTime(result);

    if (calc.error)
        calc.soap_stream_fault(std::cerr);
    else
        printf("result = %g\n", result);

    
    return 0;
}

