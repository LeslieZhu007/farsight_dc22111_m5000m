#!/bin/bash 
i=1
while [ $i -le 9 ]
do
	j=1;
	while [ $j -le $i ]
	do
		echo -n "${j}x${i}=$((i*j)) "
		((j++))
	done

	echo
	((i++))
done

