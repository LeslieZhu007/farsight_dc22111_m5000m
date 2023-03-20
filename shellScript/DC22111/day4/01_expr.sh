#!/bin/bash 
var1=10
var2=0
var3=90
expr $var1 \| $((var2++))
expr $var2 \| $((var1++)) 
expr $var3 \& $var1 
expr $var3 \< $var1 
expr $var1 \<= $var3 
expr $var3 \>= $var1
expr $var3 = $var2
echo $var2

