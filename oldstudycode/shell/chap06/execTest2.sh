#!/bin/bash

echo "Start a shell"
exec 0</etc/passwd
exec 1>a.txt
exec 2>err.txt

ca
date
ls aba
read Line1
read Line2
echo $Line1
echo $Line2 
