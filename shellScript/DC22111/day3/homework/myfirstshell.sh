#!/bin/bash 
#name: Satoshi Nakamoto
#filename: myfirstshell.sh
#purpose: for a better future
echo "Hello `whoami`"
whoami
ls -l ..
ps -ajx|grep root
echo $PATH
echo $HOME
df -h
id `whoami` | cut -d " " -f 2 
echo "Good Bye `whoami`"
