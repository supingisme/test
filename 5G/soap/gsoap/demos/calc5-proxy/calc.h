//gsoap ns service name: calc Simple calculator service 
//gsoap ns service style: rpc //gsoap ns service encoding: encoded 
//gsoap ns service namespace: http://localhost/calc.wsdl 
//gsoap ns service location: http://localhost/server.cgi 
//gsoap ns schema namespace: urn:calc 


//gsoap ns service method: add Sums two values
int ns__add(double a, double b, double *result);

//gsoap ns service method: sub Subtracts two values
int ns__sub(double a, double b, double *result);

//gsoap ns service method: mul Multiplies two values
int ns__mul(double a, double b, double *result);

//gsoap ns service method: div Divides two values
int ns__div(double a, double b, double *result);

//gsoap ns service method: pow Raises a to b
int ns__pow(double a, double b, double *result);

