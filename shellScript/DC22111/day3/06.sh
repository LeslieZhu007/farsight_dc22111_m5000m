#!/bin/bash 
var1=10
var2=12
#arr=$[var1+var2]
arr=$[var1+$var2]
echo $arr

echo "------------------------------------------"

let var3=var1+var2
echo $var3


echo "------------------------------------------"

var4=`expr $var1 \* $var2`
var5=$(expr \( $var1 + $var2 \) \* $var2)
echo $var4
echo $var5
