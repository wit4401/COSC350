#!/bin/bash
file=save.text
option='A'

echo '-------------------------------'
function DisplayMenu {
    echo 'Employee Database Simulator'
    echo '-------------------------------'
    echo 'A. Insert'
    echo 'B. Modify'
    echo 'C. Delete'
    echo 'D. Retrieve'
    echo 'E. Display'
    echo 'X. Exit Program'
    echo -n 'Please Select an Option: '
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

while [ $option != 'X' ]
do
    DisplayMenu
    read option
    echo '-------------------------------'
done

exit 0 
