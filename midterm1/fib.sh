#!/bin/bash

num1=0
num2=1
for i in $(seq 1 $1);do
    echo -n "$num1 "
    newNum2=`expr $num1 + $num2`
    num1=$num2
    num2=$newNum2
done
echo
exit 0
