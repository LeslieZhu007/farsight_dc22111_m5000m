#!/bin/bash 
read -p "please 2 file names" file1 file2
if [ -e $file1 ]
then
	gname=`ls -lh $file1|cut -d " " -f "4"`
fi
if [ -e $file2 ]
then
	gname2=`ls -lh $file2|cut -d " " -f "4"`
fi

if [ "$gname" = "$gname2" ]
then 
	echo "has same group user"
else
	echo "group user is different"
fi
