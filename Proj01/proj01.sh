#!/bin/bash
contin=yes
file=save.text

function insert{
}

function delete{
}

function modify{
}

function retrieve{
}

while [$contin -eq "yes"]
do
    option=0;
    read $option
    if [$option -eq "X"]
        contin=no
done

exit 0 
