#!/bin/bash 
read -p "please input rows:" row 
i=0
while [ $i -lt $row ] 
do 
	j=$i
	while [ $j -ge 0 ]	
	do 
		echo -n '* '
		((j--))
	done

	echo
	((i++))
done
