#!/bin/bash

USAGE="Usage:`basename $0` [ERR]"
if [ $# -lt 2 ]
then
	echo $USAGE
	exit 1
fi
case $1 in 
	q)
		ops="cvf"
		shift
		t="$1.tar"
		shift
		tmp="$*"
		;;
	p)
		ops="xvf"
		shift
		tmp="$1.tar "
		;;
	l)
		ops="tvf"
		shift
		tmp="$1.tar "
		;;
	*)
		echo "归档失败"
esac
tar $ops $t $tmp




