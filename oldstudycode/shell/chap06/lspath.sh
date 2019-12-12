#!/bin/bash
lspath (){
OLDIFS="$IFS"
IFS=":"
for var in $PATH
do
	echo "$var"
done
IFS="$OLDIFS"
}
lspath 
