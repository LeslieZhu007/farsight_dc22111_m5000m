#!/bin/bash 
read -p "please input the score:" score
if [ $score -ge 90 -a $score -le 100 ]
then
	echo A
elif [ $score -ge 80 -a $score -lt 90 ]
then
	echo B
elif [ $score -ge 70 -a $score -lt 80 ]
then
	echo B
elif [ $score -ge 60 -a $score -lt 70 ]
then
	echo D
else
	echo "You typed the wrong number"
fi

