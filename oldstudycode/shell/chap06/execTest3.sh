#!/bin/bash

exec 5<&0
exec 6>&1
exec 7>&2
exec 0</etc/passwd
exec 1>a.txt
read Line1
echo $Line1

exec 0<&5
exec 1<&6
exec 2<&7
exec 5<&-
exec 6<&-
exec 7<&-
cal
date





