
HDR_CALC:=SmsWBS.h
SRC_SERVER:=SmsWBSServer.c
SRC_CLIENT:=SmsWBSClient.c


SOAP_SRV:=soapC.c soapClient.c
SOAP_CLT:=soapC.c soapServer.c

LIBS:=-lgsoap

all: server client

	
${SOAP_SRV} ${SOAP_CLT}:${HDR_CALC}
	soapcpp2 -c ${HDR_CALC}


client:${HDR_CALC} ${SOAP_CLT}
	gcc -o client ${SRC_CLIENT} ${SOAP_CLT} ${LIBS}

server:${HDR_CALC} ${SOAP_SRV}
	gcc -o server ${SRC_SERVER} ${SOAP_SRV} ${LIBS}


clean:
	rm -rf client server *.xml *.nsmap soap*