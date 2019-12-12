#!/bin/bash

echo "INout a  string:"
read str
#if [ -n $str -a $str = "briup" ]
if [ ! -z $str -a $str = "briup" ]
then
	echo "yes"
else
	echo "no"
fi

