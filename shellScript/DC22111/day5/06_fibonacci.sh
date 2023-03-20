#!/bin/bash 
arr[0]=1
arr[1]=1
read -p "input a number:" num
for((i=2;i<num;i++))
do

	((arr[i]=arr[i-1] + arr[i-2]))

done

echo ${arr[*]}

for i in `seq 2 1 $((num-1))`
do
	arr[$i]=$[${arr[$((i-1))]} +  ${arr[$((i-2))]}]

done 
echo ${arr[*]}
