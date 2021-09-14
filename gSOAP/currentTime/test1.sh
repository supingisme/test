#!/bin/bash

if [ $1 = "proxy" ]; then
	make soapcpp2_proxy
	make server_proxy
	make client_proxy
else
	make soapcpp2
	make server
	make run_server
fi


