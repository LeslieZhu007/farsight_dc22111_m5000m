#!/bin/bash 
arr=(1 2 3 4)
brr=([0]=9 [1]=10 [2]=1999)
crr=([0]=19 [4]=34)
echo crrlen=${#crr[*]}
echo brrlen=${#brr[@]}

echo brr[0]=${#brr[0]}
echo brr[2]=${#brr[2]}

crr[0]=234
echo ${crr[0]}

crr[2]=123
echo ${crr[2]}
echo crrlen=${#crr[*]}
