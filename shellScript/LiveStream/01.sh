#!/bin/bash
if [ -d dir ] 
then
    rm dir -r
    mkdir dir 
else
    mkdir dir
fi
cd dir

for i in {1..5}
do
    echo "*******"
    filename=`uuidgen | tr '0-9' 'a-z' | cut -c 1-10`
    touch ${filename}_oldboy.html
done

for file in `ls *.html`
do
    newfilename=$(echo ${file} | cut -c 1-10)
    mv ${file} ${newfilename}_oldgirl
done