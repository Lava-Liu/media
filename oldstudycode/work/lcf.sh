#!/bin/sh


for oldname in $*
do 
   if [ -f $oldname ]
   then
   newname=` echo $oldname | tr "[A-Z]" "[a-z]"`
   if [ $oldname != $newname ]
   then
      mv $oldname $newname
     fi
  fi
done
