#!/bin/bash 
read -p "please enter 2 numbers:" var1 var2
echo $((var1+var2))
expr $var1 + $var2
