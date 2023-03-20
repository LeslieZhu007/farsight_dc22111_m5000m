#!/bin/bash 
i=0
while [ $i -lt 5 ]
do
	echo "hello world"
	((i=i+1)) #((i++))  i=$((i+1))
done

sum=0
i=0
while [ $i -le 100 ]
do
	((sum+=i))
	((i++))
done
echo "sum=$sum"
