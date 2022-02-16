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
    echo '-------------------------------'
}

function delete {
    echo 'shit'
    echo '-------------------------------'
}

function modify {
    echo 'shit'
    echo '-------------------------------'
}

function retrieve {
    echo 'shit'
    echo '-------------------------------'
}

function printDatabase {
    echo 'shit'
    echo '-------------------------------'
}

while [ $option != 'X' ] && [ $option != 'x' ]
do
    DisplayMenu
    read option
    echo '-------------------------------'
    case $option in
        a|A)
            insert ;;
        b|B)
            modify ;;
        c|C)
            delete ;;
        d|D)
            retrieve ;;
        e|E)
            printDatabase ;;
        x|X)
            echo 'Exiting Program...';;
        *)
            echo 'Invalid Input'
            echo '-------------------------------';;
    esac
done
exit 0 
