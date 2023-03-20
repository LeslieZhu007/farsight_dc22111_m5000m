#!/bin/bash 
read t
case $t in
	Y|yes|y|YES)
		echo "yes"
		;;
	N|no|n|NO)
		echo "no"
		;;
	*)
		echo "wrong input"
		;;
esac
