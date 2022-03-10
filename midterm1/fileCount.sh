#!/bin/bash

shfiles=`ls -l *.sh | wc -l`
cfiles=`ls -l *.c | wc -l`
cppfiles=`ls -l *.cpp | wc -l`
hfiles=`ls  -l *.h | wc -l`

echo "There are $shfiles .sh files"

echo "There are $cfiles .c files"

echo "There are $cppfiles .cpp files"

echo "There are $hfiles .h files"

