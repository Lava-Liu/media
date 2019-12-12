#!/bin/bash
#This's first sh-script
#read:shell 中从标准输入中读取信息

echo "Please input a string:"
read var
msg="Message"

#var1=${var:-$msg}

#var1=${var3:-$msg}

#var1=${var:=$msg}

#var1=${var3:=$msg}
var1=${var:?$msg}
echo "_____________________________________"
echo $var
echo $var1

