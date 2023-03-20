#!/bin/bash 
read -p "please enter the name of the software:" name
read -p "please enter your choice:" choice

case $choice in
	Y|yes|y|YES)
		echo "you entered yes,now begin to download the software:$name"
		sudo apt-get download $name
		;;
	N|no|n|NO)
		echo "you entered no,nothing will be done"
		;;
	*)
		echo "wrong input"
		exit
		;;
esac
