#!/bin/bash 
var1=10  #no spaces are allowed
echo $var1
echo ${var1}

var2="hello world"
var3='hello world1'
echo $var3
echo $var2
var3="$var1 $var2"
echo $var3
echo ${var3}123
