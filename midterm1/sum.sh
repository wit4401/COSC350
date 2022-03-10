#!/bin/bash

sum=0
for i in $(seq 1 $#);do
    eval num=\$$i
    sum=`expr $num + $sum`
done
echo "Sum is $sum"
exit 0
