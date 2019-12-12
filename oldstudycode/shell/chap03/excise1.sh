#!/bin/bash

echo "Pleas Input a username"
read var

var1='{cat /etc/passwd | awk -F: '{print $* }' | grep var | awk -F: '{print $5}'}'
echo $var1
