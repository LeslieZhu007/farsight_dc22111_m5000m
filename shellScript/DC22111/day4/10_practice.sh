#!/bin/bash 
read -p "please input the username:" username
var=$(grep "^$username" /etc/passwd -ni)
echo $var
if [ -n "$var" ]
then
	echo "$username exists"
else
	echo "$username does not exist,prepare to add user $username"
	sudo adduser $username
	var=$(grep "^$username" /etc/passwd -ni) #id -u $username
	echo $var
fi

