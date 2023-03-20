#!/bin/bash 
sum=0
for i in `seq 1 1 100`
do
	((sum+=i))
	((i++))
done
echo $sum 
#**************************************************

sum=0
for((i=1;i<=100;i++))
do 
	((sum+=i))
done
echo $sum

#**************************************************
sum=0
for i in {1..100} 
do
	((sum+=i))
	((i++))
done
echo $sum 

#**************************************************
sum=0
for i in `seq 0 2 100`
do
	((sum+=i))
	((i++))
done
echo $sum 


#**************************************************

sum=0
for((i=1;i<=100;i++))
do 
	if [ $((i%2)) -eq 0 ] 
	then

		((sum+=i))
	fi
done
echo $sum


#**************************************************
sum=0
for i 
do
	((sum+=i))
done
echo $sum 
