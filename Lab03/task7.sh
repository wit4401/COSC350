#!/bin/bash

num=0;
echo "Task 7:"
echo -n "Enter a value: "
read num

echo -n "$num!="
res=1

while [ $num -gt 1 ]
do
    res=$((num*res))
    let num--
done
echo "$res"
exit 0
