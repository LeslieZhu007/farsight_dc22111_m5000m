#!/bin/bash 
for var in `ls *.txt`
do
	echo $var
	pos=`expr index $var "."`
	sub_str=`expr substr $var 1 $((pos-1))`
	echo $sub_str
	mkdir $sub_str

done 


for var in `ls m*.txt`
do 
	file=`cut -d "." -f 1 "$var"`
	echo file=$file
done 

