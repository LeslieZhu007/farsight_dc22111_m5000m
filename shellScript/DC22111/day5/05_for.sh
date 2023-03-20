#!/bin/bash 
for i in {1..4}
do
	mkdir m$i
	mv m$i.txt m$i
done


for filename in `ls m*.txt`
do
	mkdir `echo $filename|cut -d "." -f "1"`
	mv $filename `echo $filename|cut -d "." -f "1"`
done
