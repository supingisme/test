
HDR_CALC:=calc.h
SRC_SERVER:=calcServer.cc
SRC_CLIENT:=calcClient.cc


SOAP_SRV:=soapC.cpp soapcalcService.cpp
SOAP_CLT:=soapC.cpp soapcalcProxy.cpp

LIBS:=-lgsoap++

all: server client

	
${SOAP_SRV}:${HDR_CALC}
	soapcpp2 -S -i ${HDR_CALC}
	
${SOAP_CLT}:${HDR_CALC}
	soapcpp2 -C -i ${HDR_CALC}


client:${HDR_CALC} ${SOAP_CLT}
	g++ -o client ${SRC_CLIENT} ${SOAP_CLT} ${LIBS}

server:${HDR_CALC} ${SOAP_SRV}
	g++ -o server ${SRC_SERVER} ${SOAP_SRV} ${LIBS}


clean:
	rm -rf client server *.xml *.nsmap soap*