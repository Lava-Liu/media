#!/bin/bash
echo "Number"
read counter;
i=1
#tmp=0
#leg=0
while [ $i -le $counter ]
do
	echo -n "$1 只青蛙 $i 张嘴"
	tmp=$(($i*2))
	leg=$(($i*4))
	echo "$tmp只眼睛 $leg条腿"
	((i++))

done
