#!/bin/bash 
var1=10
var2=20
function print()
{

	echo "shell function called"

}

add()
{
	echo $((var1+var2))

}

add1()
{
	local o=10
	unset o
	echo $o
	echo $(($1+$2))

}
var3=`add1 12 34`
echo $var3

add3()
{
	#return $((var1+var2))	
	return 255
}
add3
var=$?
echo $var
add1 12 35
echo $o 




