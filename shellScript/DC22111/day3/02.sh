#!/bin/bash 
a=`ls`
echo $a
b=$(pwd)
echo $b
var1=$(grep "linux" /etc/passwd -niR)
echo $var1
