#!/bin/bash 
var1=10
var2=20
val=$(($var1+var2))
echo $val 
((var3=var1+$var2))
echo $var3

var4=$((var1++,var2++,++var1,++var2))
echo var4=$var4
echo var1=$var1
