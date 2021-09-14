#include "soap/soapcalcProxy.h"
#include "soap/calc.nsmap"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    double a = 4;
    double b = 2;
    double result;
    calcProxy calc;
    calc.soap_endpoint = "http://localhost:65531";

    calc.add(a,b,&result);
    cout<<a<<"+"<<b<<"="<<result<<endl;

    calc.sub(a,b,&result);
    cout<<a<<"-"<<b<<"="<<result<<endl;
    return 0;
}
