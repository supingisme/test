#!/bin/bash
# rongtao

g++ server.cpp soap/*.cpp -I soap/ -lgsoap++ -lgsoap -o server
g++ client.cpp -I soap/ -lgsoap++ soap/soapcalcProxy.cpp soap/soapC.cpp -o client
