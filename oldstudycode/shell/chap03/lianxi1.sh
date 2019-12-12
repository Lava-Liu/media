#!/bin/bash
#测试变量替换
myvar=hello
newvar=${myvar:+hi}
echo "myvar:$myvar"
echo "newvar:$newvar"
