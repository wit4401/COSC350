#!/bin/bash
file=save.text
option='A'

function DisplayMenu {
    echo '----------------------------------------------------------------------------------------'
    echo 'A'
    echo 'B'
    echo 'C'
    echo 'D'
    echo 'E'
    echo 'X'
}

function insert {
    echo 'shit'
}

function delete {
    echo 'shit'
}

function modify {
    echo 'shit'
}

function retrieve {
    echo 'shit'
}

function printDatabase {
    echo 'shit'
}

while [ $option == 'A' ] || [ $option == 'B' ] || [ $option == 'C' ] || [ $option == 'D' ] || [ $option == 'E' ]
do
    option='N'
    DisplayMenu
    read $option
    if [ $option == 'A' ]; then
        insert
    elif [ $option == 'B' ]; then
        modify
    elif [ $option == 'C' ]; then
        delete
    elif [ $option == 'D' ]; then
        retrieve
    elif [ $option == 'E' ]; then
        display
    fi
done

exit 0 
