#!/bin/bash

#trap "date"  SIGTSTP

trap "handler" SIGTSTP
handler(){

	echo "The <Ctr+Z> clicked"
}


while :
do
	:
done

trap  20 


