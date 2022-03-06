#!/bin/bash
sum=0
for i in $(seq 1 $1);do
    sum=`expr $sum + $i`
done

echo "The sum from 1 to $1 is $sum"
exit 0
