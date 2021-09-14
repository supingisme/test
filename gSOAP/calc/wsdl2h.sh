#!/bin/bash

wget http://www.genivia.com/calc.wsdl
wsdl2h -o calc-c++.h  calc.wsdl

# To build without STL,
wsdl2h -s -o calc-STL.h  calc.wsdl

# To build a pure C application,

wsdl2h -c -o calc-c.h  calc.wsdl

