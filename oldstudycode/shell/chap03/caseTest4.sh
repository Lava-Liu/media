#!/bin/bash

echo "Input a string:"

read str

case $str in
	*[!0-9]*)
		echo "not a number string"
		;;
	*)
		echo "It a number string "
esac
