#!/bin/bash 
var1=10
var2=20
if [ $var1 -eq $var2 ]
then
	echo "equal"
elif [ $var1 -gt $var2 ]
then
	echo "var1 > var2"
elif [ $var1 -lt $var2 ]
then
	echo "var1 < var2"
elif [ $var1 -ne $var2 ]
then
	echo "var1 != var2"
fi
