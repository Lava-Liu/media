#!/bin/bash

echo "Input a filename: "
read file

if [ -n $file ] && [ -f $file ] && [-r $file ] && [ -w $file ]
then
	echo "$file :R/W"
else
	echo "$file:No R/W"
fi
