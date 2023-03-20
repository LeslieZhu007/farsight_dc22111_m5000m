#!/bin/bash 
read -p "please input year and month:" year month

case $month in
	1|3|5|7|8|10|12)
		echo "$month has 31 days"
		;;
	4|6|9|11)
		echo "$month has 30 days"
		;;
	2)
		if ((year%4==0 && year%100!=0 || year%400==0))
		then 
			echo "$month has 28 days"
		else
			echo "$month has 29 days"
		fi
		;;
	*)
		echo "wrong type"
		;;
esac

#if [ $((year%4)) -eq 0 -a $((year%100)) -ne 0 -o $((year%400)) -eq 0 ]
