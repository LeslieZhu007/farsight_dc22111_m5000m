#!/bin/bash 
read -p "please enter the expression:" var
#echo $var
pos_plus=`expr index $var "\+"`
pos_minus=`expr index $var "\-"`
if [ $pos_plus -ne 0 ]
then
	#echo +
	op1=$(expr substr $var 1 $((pos_plus-1)))
	#echo $op1
	op2=$(expr substr $var $((pos_plus+1)) `expr length $var`)
	#echo $op2
	echo $var=$((op2+op1))
fi


if [ $pos_minus -ne 0 ]
then
	op1=$(expr substr $var 1 $((pos_minus-1)))
	#echo $op1
	op2=$(expr substr $var $((pos_minus+1)) `expr length $var`)
	#echo $op2
	echo $var=$((op1-op2))

fi


