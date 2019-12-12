#!/bin/bash

echo "Input a charactor:"
read ch

case $ch in
	[0-9])
		echo "a number"
		;;
	[a-zA-Z])
		echo "a char"
		;;
	*)
		echo "symbol"
esac

