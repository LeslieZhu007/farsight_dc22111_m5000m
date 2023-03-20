#!/bin/bash 
mkdir subdir1 subdir2
cp /etc/passwd ./subdir1
cp /etc/group ./subdir2
mv subdir2 subdir 
tar -Jcvf 1.tar.xz ./subdir1
cp 1.tar.xz ./subdir
cd ./subdir 
tar -xvf 1.tar.xz
cd ..
ls subdir 
grep "linux" subdir -niR
