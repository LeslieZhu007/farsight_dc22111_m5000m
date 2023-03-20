#!/bin/bash 
read -p "please input filename" filename
if [ -f $filename ]
then
	if [ -x $filename ]
	then 
		echo "has executable permission"
	else
		chmod a+x $filename
		echo "add permission success"
	fi 
fi
