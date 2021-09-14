
all:


genheader:
	wsdl2h -c -o calc.h  calc.wsdl

soap:
	soapcpp2 -c calc.h
	
client:
	gcc -o client client.c soapClientLib.c  -lgsoap

server:
	
clean:
	rm -rf client 