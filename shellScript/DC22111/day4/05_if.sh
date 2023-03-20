#!/bin/bash 
string=hello
string1=world
if [ -z $string2 ]
then
	echo "string is empty"
else
	echo "string is not empty"
fi

if [ $string = $string1 ]
then
	echo "2 strings are equal"
else
	echo "not equal"
fi

if [ $string != $string1 ]
then
	echo "2 strings are not equal"
else
	echo " equal"
fi

