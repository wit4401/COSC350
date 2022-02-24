#!/bin/bash
if [ "$#" -ne 1 ];then
    echo "Please include one parameter!"
    exit 1
fi
len=`expr length $1`
sub=`expr substr $1 2 3`
echo "Length of parameter: $len"
echo "Substring of input from position 2 to 4: $sub"
exit 0
