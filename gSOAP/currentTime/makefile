

all:

soapcpp2:
	soapcpp2 currentTime.h

soapcpp2_proxy:
	soapcpp2 -i currentTime.h

server:
	c++ -o server currentTime.cpp soapC.cpp soapServer.cpp -lgsoap++

server_proxy:
	c++ -o server_proxy currentTime_proxy.cpp soapC.cpp soapService.cpp -lgsoap++

client_proxy:
	c++ -o client_proxy client_proxy.cpp soapC.cpp soapProxy.cpp -lgsoap++

run_server:
	./server < ns.currentTime.req.xml


clean:
	rm -rf server server_proxy client_proxy soap* *.xml ns.*

	
