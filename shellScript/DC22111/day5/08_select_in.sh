#!/bin/bash 
select var in `ls`
do
	str=`echo $var|cut -d "." -f 2`
	if [ $str = "bak" ]
	then
		rm $var	
	else
		echo $var
	fi
done

