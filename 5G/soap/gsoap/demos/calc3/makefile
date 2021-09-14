
LIBS:=-lgsoap++

all: server client

gen_h:
	soapcpp2 -i calc.h

client:
	g++ -o client calcClient.cc soapC.cpp soapcalcProxy.cpp ${LIBS}

server:
	g++ -o server calcServer.cc soapC.cpp soapcalcService.cpp ${LIBS}


clean:
	rm -rf client server