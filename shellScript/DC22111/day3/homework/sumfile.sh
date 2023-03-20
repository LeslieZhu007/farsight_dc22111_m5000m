#!/bin/bash 
var1=$(ls -l /etc | grep "^[d]" | wc -l)
var2=$(ls -l /var | grep "^[d]" | wc -l)
var3=$(ls -l /usr | grep "^[d]" | wc -l)
echo "dir in /etc is $var1,normal files:$(($(ls -l /etc|wc -l)-var1-1))" 
echo "dir in /var is $var2,normal files:$(($(ls -l /var|wc -l)-var2-1))" 
echo "dir in /usr is $var3,normal files:$(($(ls -l /usr|wc -l)-var3-1))" 
