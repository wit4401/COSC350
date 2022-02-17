#!/bin/bash

echo "Task 9:"
echo -n "Please enter the directory path (path/to/file/from/root no ~): "
read dir
path=$PWD
cd /
if [ -d $dir ];then
    cd $dir
    num=3
    while [ $num -gt 0 ];do
        echo -n "Please enter the file name: "
        read file
        if [ -f $file ] && [ -r $file ];then
            echo -n "Please enter a word to search for: "
            read word
            if grep -q $word $file
            then
                echo "$word was found!"
                cd /
                cd $path
                exit 0
            else
                echo "$word not found!"
                cd /
                cd $path
                exit 4
            fi
        else
            let num--
            echo "File does not exist or is not readable ($num more attempts)."
        fi
        if [ ! -f $file ] && [ $num -eq 0 ];then
            cd $path
            exit 2
        elif [ -r $file ] && [ $num -eq 0 ];then
            cd $path
            exit 3
        fi
    done
    exit 2
else
    echo "This is not an existing directory."
    cd $path
    exit 1
fi
