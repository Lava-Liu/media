#!/bin/bash
num=1
until  [ $num -eq 10 ]
do
	echo "$num"
	((num++))

done
