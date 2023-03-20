#!/bin/bash 
i=1
j=1
while [ $i -le 9 ]
do
	j=1
	while [ $j -le 9 ]
	do
		if [ $j -gt $i ]
		then
			break
		fi
		echo -n $j "*" $i = $((i*j)) " "
		((j++))
	done
	((i++))
	echo ""
done
