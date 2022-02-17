#!/bin/bash

echo "Task 8:"
res=0
if [ "$#" -eq 1 ];then
    len=`expr length $1`
    for i in `seq 1 $len`;do
        digit=`expr substr $1 $i 1`
        res=`expr $res + $digit`
    done
    echo "The sum of each digit in $1 is $res"
else
    echo "Must pass one parameter!"
fi
exit 0
