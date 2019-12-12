#!/bin/bash


num=1
while [ $num -le 100 ]
#while ((num++<=100))
do

	((num++))	
	tmp=$(($num % 10))
	if [ $tmp -eq 4 ]
	then
		continue
	fi
	echo -n " $num "
	#((num++))	

done

