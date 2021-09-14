#include "soap/soapcalcService.h"
#include "soap/calc.nsmap"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    calcService calc;
    int port = 65531;

    if (calc.run(port)) {
        cerr << "Calc service run failed" << endl;
        exit(0);
    }
    return 0;
}

int calcService::add(double a, double b, double* result) {
    *result = a + b;
    return SOAP_OK;
}

int calcService::sub(double a, double b, double* result) {
    *result = a - b;
    return SOAP_OK;
}
