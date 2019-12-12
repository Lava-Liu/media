#!/bin/bash
echo "Input yout choice:"
read ANS
case $ANS in
	Yes)
		echo "Y"
		ANS=y
		;;
	yes)
		echo "Y"
		ANS=y
		;;
	y)
		echo "Y"
		ANS=y
		;;
	*)
		echo "n"
esac

