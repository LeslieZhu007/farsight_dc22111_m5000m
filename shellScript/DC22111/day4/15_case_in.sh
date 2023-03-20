#!/bin/bash 
read -p "please input something" var
case $var in 
	[0-9])
		echo "number"
		;;
	[a-zA-Z])
		echo "alphabet"
		;;
	*)
		echo "other"
		;;
esac
