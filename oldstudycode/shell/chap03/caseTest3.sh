#!/bin/bash

echo "Input a string:"
read str

case $str in
#	cat) 
	[0-9]*)
		#echo "input cat"
		echo "1y"
		;;
	?[0-9]*)
		echo "2y"
		;;
	*)
		echo "No"
esac
