#!/bin/bash

if [ $# -eq 0 ] 
then
	echo "No param"
	exit -1
fi

case $1 in 
	-a|a)
		echo "a"
		;;
	-b|b)
		echo "b"
		;;
	*)
		echo "Others"
esac
echo "Finished"
