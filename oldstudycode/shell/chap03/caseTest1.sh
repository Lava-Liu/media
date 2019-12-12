#!/bin/bash

echo "Input choice(a,b,c):"
read var

case $var in
	a|A)
		echo "Choose a!"
		;;
	b|B)
		echo "Choose b!"
		;;
	c|C)
		echo "Choose c!"
		;;
	*)echo "Other"
esac
