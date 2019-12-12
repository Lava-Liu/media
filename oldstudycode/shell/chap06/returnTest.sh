#!/bin/bash

fun()
{
	if [ $1 -eq 0 ]
	then
		return 100
set -x
	elif  [ $1 -eq 1 ]
	then
		return 0
	else
		return 10
	fi
set +x
}

fun 0 
echo "fun(0):$?"
fun 1
echo "fun(1):$?"
fun 10
echo "fun(10):$?"

