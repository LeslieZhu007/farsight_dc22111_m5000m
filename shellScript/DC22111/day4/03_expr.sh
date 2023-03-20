#!/bin/bash 
read -p "please input a network addr:" string

index1=`expr index  $string  "."`
sub_str1=`expr substr $string 1 $(($index1-1))`
arr[0]=$sub_str1
echo sub_str1=$sub_str1


len=$(expr length $string)
sub_str2=`expr substr $string $(($index1+1)) $len` 
index2=`expr index $sub_str2 "."`
sub_str3=`expr substr $sub_str2 1  $(($index2-1))`
echo sub_str3=$sub_str3
arr[1]=$sub_str3


sub_str4=`expr substr $sub_str2 $(($index2+1)) $len`
echo sub_str4=$sub_str4
arr[2]=$sub_str4
echo ${#arr[@]}
echo ${arr[@]}
