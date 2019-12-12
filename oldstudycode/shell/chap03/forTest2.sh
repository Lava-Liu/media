#!/bin/bash
i=1
sum=0

for ((i=0; i < 101 ; i++ ))
do
	sum=$(($sum+$i))
done
echo $sum


