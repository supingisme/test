// File: currentTime_proxy.cpp
#include "soapService.h" // include the proxy declarations
#include "ns.nsmap" // include the XML namespace mappings

int main()
{
    // create server and serve one CGI-based request:
    Service server;
    
    server.serve();

#if 1
//    To run the server as a stand-alone iterative (non-multithreaded) server on port 8080 until accept()
//    timeout times out or an error occurs:
    if (server.run(8080))
        server.soap_stream_fault(std::cerr);
#else
//    To run the server as a stand-alone iterative server on port 8080 while ignoring common errors until
//    a TCP error occurs:
    while (server.run(8080) != SOAP_OK)
    {
        if(server.error == SOAP_TCP_ERROR)
            break;
        server.soap_stream_fault(std::cerr);
    }
#endif    
    server.destroy();
}
int Service::currentTime(time_t& response)
{
    response = time(0);
    return SOAP_OK;
}

