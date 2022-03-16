#!/bin/bash

shfiles=`ls -l *.sh | wc -l`
cfiles=`ls -l *.c | wc -l`
cppfiles=`ls -l *.cpp | wc -l`
hfiles=`ls  -l *.h | wc -l`

if [ $shfiles -ne 0 ];then
    echo "There are $shfiles .sh files"
fi

if [ $cfiles -ne 0 ];then
    echo "There are $cfiles .c files"
fi

if [ $cppfiles -ne 0 ];then
    echo "There are $cppfiles .cpp files"
fi

if [ $hfiles -ne 0 ];then
    echo "There are $hfiles .h files"
fi
