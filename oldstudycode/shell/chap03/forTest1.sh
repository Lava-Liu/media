#!/bin/bash
counter=1
#for循环后面的列表是以空白字符（空格）作为划分的
#yonglaidngjishuqishiyong
#read nums

#for var in 1 2 3 4 5 6 7
#for var in $nums
#for var in `date`
#在 ./test 后加上列表
for var 
do
	echo "$counter:$var"
	counter=$(($counter+1))
done
