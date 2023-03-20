#!/bin/bash 
arr=(`ls /etc`)
brr=(`ls /var`)
crr=(`ls /usr`)
count1=${#arr[*]}
count2=${#brr[*]}
count3=${#crr[*]}
((sum=count1+count2+count3))
echo $sum


drr=(`ls /etc` $(ls /var) `ls /usr`)
