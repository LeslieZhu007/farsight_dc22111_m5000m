#!/bin/bash 
for((i=0;i<3;i++))
do
	echo "1st level xxxxxxxxxxxxxxxxx$i"
	for j in `seq 1 3`
	do
		echo "2nd level xxxxxxxxxxxxxxxxx$j"
		for k in {1..4}
		do 
			echo "3rd level xxxxxxxxxxxxxxxxx$k"
			if [ $k -eq 3 ]
			then
				#break;
				#break 2;
				break 3
				#continue
				#continue 3
			fi
			echo "3rd level ###################"
		done
		echo "2nd level ###################"
	done
	echo "1st level ########################"
done
