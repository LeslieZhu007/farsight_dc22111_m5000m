#!/bin/bash 
for var in `ls ./*.c`
do
	if [ -s ./$var ]	
	then
		gcc ./$var 
	fi
done


for var in `ls ~/farsight |  grep "\.c$"`
do
	if [ -s $var ]
	then
		gcc ~/farsight/$var 
	fi

done
