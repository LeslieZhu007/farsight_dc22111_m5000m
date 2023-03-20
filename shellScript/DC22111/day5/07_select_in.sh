#!/bin/bash 
select c in windows mac linux redhat
do
	case $c in
		windows)
			echo "windows selected"
			;;
		mac)
			echo "mac selected"
			;;
		linux)
			echo "linux selected"
			;;
		redhat)
			echo "redhat selected"
			;;
		*)
	esac
done
