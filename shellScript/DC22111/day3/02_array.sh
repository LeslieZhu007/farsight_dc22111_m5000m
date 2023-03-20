#!/bin/bash 
arr=(`ls`)   #arr=($(ls))
echo arrcount=${#arr[@]}
echo arrelements=${arr[*]}
