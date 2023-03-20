#!/bin/bash 
mkdir /home/linux/copy
cd /home/linux/copy
sudo cp /etc/shadow test
ls -lh test
sudo chown root test
sudo chmod o=- test
