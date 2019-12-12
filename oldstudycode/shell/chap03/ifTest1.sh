#!/bin/bash

echo "Input a file or dir:"
read name #read form stdin : 
#if test -f $name
if [ -f $name ]
then
	echo "$name is a normal file "
elif [ -d $name ] 
then
	 echo "$name is a directory"
 else
	echo  "Other"
 fi

