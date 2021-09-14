//gsoap ns service name: calc Simple calculator service 
//gsoap ns service style: rpc //gsoap ns service encoding: encoded 
//gsoap ns service namespace: http://localhost/calc.wsdl 
//gsoap ns service location: http://localhost/server.cgi 
//gsoap ns schema namespace: urn:calc 
int ns__add(double a, double b, double *result); 
int ns__sub(double a, double b, double *result);

