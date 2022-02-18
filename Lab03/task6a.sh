#!/bin/bash

base=0
num=0

while [ $base -lt 4 ] || [ $num -eq 0 ];do
    echo -n "Base Value: "
    read base
    num=`expr $base % 2`
    if [ $base -lt 4 ];then
        echo "Base Value too small!"
    elif  [ $num -eq 0 ];then
        echo "Base Value must be odd!"
    fi
done

exit 0
