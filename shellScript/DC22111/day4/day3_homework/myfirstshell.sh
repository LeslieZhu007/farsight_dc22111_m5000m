#!/bin/bash 
name=$(whoami)
echo "hello $name"
name1=`hostname`
echo "$name1"
ls ../ 
ps -ajx|grep "root"
echo $PATH
echo $HOME
sudo df /dev/sda1 
id -g $name 
echo "GoodBye"
