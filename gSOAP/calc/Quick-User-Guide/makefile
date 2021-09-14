WSDL_WEB=http://www.genivia.com/calc.wsdl
WSDL=calc.wsdl
HDR=calc.hpp


all:

soapcpp2: ${HDR}
	soapcpp2 ${HDR}

${HDR}: ${WSDL}
	wsdl2h -o ${HDR} ${WSDL}

${WSDL}:
	wget ${WSDL_WEB}

clean:
	rm -rf ${HDR} *.xml soap* *.nsmap


