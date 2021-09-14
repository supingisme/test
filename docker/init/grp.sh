#The docker group

#Add the Docker group
sudo groupadd docker

#Add ourselves to the group
sudo gpasswd -a $USER docker

#Restart the Docker daemon
sudo service docker restart

#Log out
exit
