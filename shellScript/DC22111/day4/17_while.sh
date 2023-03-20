#!/bin/bash 
read -p "please input a row:" row
i=0
j=0
while [ $i -lt $row ]
do
	while [ $j -lt $((2*(i+1)-1)) ] 
	do
		echo -n "*"
		((j++))
	done

	echo 
	((i++))
done
