#!/bin/bash 
arr=($(ls /etc | grep "^p" -i))
echo ${#arr[@]}
echo $(ls /etc | grep "^p" -i| wc -w)
