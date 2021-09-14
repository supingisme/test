// File: currentTime.cpp
#include "soapH.h" // include the generated declarations
#include "ns.nsmap" // include the XML namespace mappings

int main()
{
    // create soap context and serve one CGI-based request:
    return soap_serve(soap_new());
}
int ns__currentTime(struct soap *soap, time_t& response)
{
    response = time(0);
    return SOAP_OK;
}

