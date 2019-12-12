#!/bin/bash

pfun () {
	num1=$1
	num2=$2
	 if [ $num1 -eq $num2 ]
	 then
		 echo  "="
	 elif [ $num1 -lt $num2 ]
	 then
		 echo "<"
	 else
		 echo ">"
	 fi
 }
