#!/bin/bash 
arr=(1 2 3 4 5)
brr=(7 8 9 10)
crr=(${arr[*]} ${brr[@]})
echo crr_ele=${crr[*]}

crr=(${arr[*]}${brr[@]})
echo crr_ele=${crr[*]}
