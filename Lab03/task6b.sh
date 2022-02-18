#!/bin/bash

base=0
num=0
tail=0

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

while [ $tail -le 0 ];do
    echo -n "Tail value: "
    read tail
    if [ $tail -le 0 ];then
        echo "Tail value must be positive!"
    fi
done

tail=`expr $base + $tail`
half=`expr $base / 2`
for i in `seq  1 $half`;do
space=`expr $base - 2 \* $i`
    for j in `seq 1 $space`;do
        echo -n ' '
    done
    star=`expr 2 \* $i - 1`
    for j in `seq 1 $star`;do
        echo -n '*'
    done
    echo
done
for i in `seq 1 $tail`;do
    echo -n '*'
done
echo 
for i in `seq $half -1 1`;do
    space=`expr $base - 2 \* $i`
    for j in `seq 1 $space`;do
        echo -n ' '
    done
    star=`expr 2 \* $i - 1`
    for j in `seq 1 $star`;do
        echo -n '*'
    done
    echo
done
exit 0
