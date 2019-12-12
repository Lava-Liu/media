#!/bin/bash
echo "Please Input a time year month"
read year mon

echo "$year"
echo "$mon"
if [ $year%4=0 ] || [ $year%400=0 ]&&[ $year%100!=0 ]
then
	if [ $mon -eq 2 ]



	then
		echo "29"
	else
		if [ $mon -le 7 ]&&[ $mon%2=0 ]||[ $mon -ge 8 ]&&[ $mon%2=1 ]
		then
			echo "30"
		else
			echo "31"
			fi
		fi
	fi
	
		
	

	

	
