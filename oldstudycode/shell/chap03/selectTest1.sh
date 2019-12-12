#!/bin/bash
PS3="Input your choice:"

select var in "cat" "dog" "pig"
do
	echo "var:$var"
    break
done
