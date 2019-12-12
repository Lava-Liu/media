#!/bin/bash
while getopts "ab:c" opt
do
	case $opt in
		a)
			echo "a, \$ARG:$OPTARG"
			;;
		b)
			echo "b, \$OPTARG:$OPTARG"
			;;
		c)
			echo "c"
			;;
		*)
	esac
done
