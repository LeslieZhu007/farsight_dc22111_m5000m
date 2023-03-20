#!/bin/bash 
if [ -d /home/linux/farsight ]
then
	echo "file exists and is directory"
fi

if [ -r ../day4 ]
then 
	echo "file has file read permission"
fi


