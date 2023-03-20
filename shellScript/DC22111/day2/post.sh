#!/bin/bash 
echo $0
echo $1
echo $9
echo ${10}
echo $#
echo $*
echo $@
readonly var1=$4
echo var1=${var1}
var1=34
var2=90
echo var2=$var2
unset var2
echo var2=$var2
local var3=98

