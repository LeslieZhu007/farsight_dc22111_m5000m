#!/bin/bash 
echo `whoami`
string=$(whoami|id -u)
string=$(whoami | id | cut -d " " -f "1")
echo $string 
