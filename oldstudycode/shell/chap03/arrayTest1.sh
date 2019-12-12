#!/bin/bash
#ce shi shu zu 

var1=(1 2 3 4 5 6 7)
var2=([1]=2 [2]=3)
var3 [2]=4
echo ${var1[*]}
echo ${var1[@]}
var4[0]="briup0"
var4[1]="briup1"
echo ${var4[*]}
echo ${var4[@]}
var5  <  ${var1[*]} 
var6 <  ${var1[@]} 
echo ${var5[2]}
echo ${var6[2]}

