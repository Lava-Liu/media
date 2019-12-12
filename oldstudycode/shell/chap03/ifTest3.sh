#!/bin/bash

echo "Input two num:"
read num1
read num2
#read nums
#echo ${nums[*]}
if [ $num1 -eq $num2 ]
then
	echo "="
elif [ $num1 -lt $num2 ]
then
    echo "<"
else
    echo ">"
fi	
