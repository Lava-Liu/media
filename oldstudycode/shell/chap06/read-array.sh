#!/bin/bash
#array=(1 2 3 4 5)
#array=([0]=3 [2]=10 [3]=40)
#array[0]=10
#array[1]=50
echo "Input a array:"
read num1[0] num2[1] num3[2] num4[3]

echo "${num[1]} ${num[2]} ${num[3]} ${num[4]}"

echo ${num[0]}
echo ${#num[*]}
echo ${num[*]}
echo ${num[@]}

