#include "soapH.h" // include all interfaces (library and generated)
#include "calc.nsmap" // import the generated namespace mapping table
int main()
{
	double sum;
	struct soap soap; // the gSOAP runtime context
	soap_init(&soap); // initialize the context (only once!)
	if (soap_call_c__add(&soap, NULL, NULL, 1.0, 2.0, &sum) == SOAP_OK)
		std::cout << "Sum = " << sum << std::endl;
	else // an error occurred
		soap_print_fault(&soap, stderr); // display the SOAP fault message on the stderr stream
	soap_destroy(&soap); // delete deserialized class instances (for C++)
	soap_end(&soap); // remove deserialized data and clean up
	soap_done(&soap); // detach the gSOAP context
	return 0;
}
