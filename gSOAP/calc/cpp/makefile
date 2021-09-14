
all:


genheader:
	wsdl2h -o calc.hpp  calc.wsdl

soap:
	soapcpp2 -i -Iimport calc.hpp
	
client:
	g++ -o client client.cc soapC.cpp soapcalcProxy.cpp -lgsoap++

server:
	
clean:
	rm -rf client 