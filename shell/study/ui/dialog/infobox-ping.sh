#!/bin/bash

ip=127.0.0.1

 while ping $ip -c 1
 do
	string=`ping $ip -c 1| grep "bytes from"`
	dialog --title "Ping $ip"	\
				   --infobox "$string" 20 60
	sleep 1
	clear
done
