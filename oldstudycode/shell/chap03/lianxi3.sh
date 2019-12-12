#!/bin/bash

x=0
while [ $x -lt 10 ]
do
	echo -e "0 \c"
	y=$(($x-1))
	x=$(($x+1))
	z=0
	while [ $y -ge 0 ] 
	do
		y=$(($y-1))
	    z=$(($z+1))	
		echo -e "$z \c"
	done
	echo -e "\n"
done

