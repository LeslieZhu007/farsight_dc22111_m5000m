#!/bin/bash 
read var1
case $var1 in 
	89)
	echo 89
	;;
	100|90)
	echo "(100,90)"
	;;
	[90-100])
	echo "[100,90]"
	;;
	*) # default in C
esac
