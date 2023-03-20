#!/bin/bash 
var=$(head -10 /etc/passwd | tail -1 | cut -d ":" -f 3)
var1=$(head -20 /etc/passwd | tail -1 | cut -d ":" -f 3)

echo $var
echo $var1
echo "id sum is:$((var+var1))"
