#!/bin/bash
echo -n "Input a string"
read str

if [ -n $str ];then 
	echo "not Null"
	if [ $str = "briup" ];then
		 echo "briup"
	 else
		 echo "other"
	 fi
 else
	 echo "Null"
 fi

