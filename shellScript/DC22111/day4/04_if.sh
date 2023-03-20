#!/bin/bash 
var1=20
var2=10
var22='hello world'
var3=0
if [[ $var1 && $var2 ]]
then
	echo 1
fi

if [ $var1 -a $var2 ]
then
	echo 1
fi
if test $var1 -a $var2 
then
	echo 1
fi
if [ $var1 -o $var3 ]
then 
	echo 3
fi
#------------String Operation----------------------
if [[ -n $var22 ]]
then
	echo "var22 is not empty"
fi

if [ "$var22" ]
then
	echo "var22 is not empty" 
fi
