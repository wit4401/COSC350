#!/bin/bash
file=employee.db
option='A'
criteria=0

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
    echo -n 'Enter First Name: '
    read first
    echo -n 'Enter Last Name: '
    read last
    echo -n 'Enter SSN: '
    read social
    echo -n 'Enter Birthday:'
    read birth
    echo -n 'Enter Salary: '
    read salary
    echo "$first $last $social $birth $salary">>$file
    echo '-------------------------------'
}

function delete {
    social='xx-xxx-xxxx'
    delete='m'
    echo -n 'Enter SSN of employee: '
    read social
    while [ $delete != 'n' ] && [ $delete != 'y' ]; do
        echo -n "Are you sure you want to delete $social (y/n)? "
        read delete
        if [ $delete != 'n' ] && [ $delete != 'y' ]; then
            echo 'Invalid Input'
        fi
    done
    echo '-------------------------------'
}

function modify {
    social='xx-xxx-xxxx'
    newLast='0'
    newFirst='0'
    newDate='0'
    newSal='0'
    echo -n 'Please Enter the SSN of the employee to be modified: '
    read social;
    while [ "$criteria" -ne 1 ] && [ "$criteria" -ne 2 ] && [ "$criteria" -ne 3 ] && [ "$criteria" -ne 4 ]; do
        echo '1. Last Name'
        echo '2. First Name'
        echo '3. DOB'
        echo '4. Salary'
        echo -n 'Please select a value: '
        read search
        case $search in
            1)
                echo -n 'Enter the new First Name: '
                read newLast
                while [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; do
                    echo -n "Are you sure you want to change the Last Name of $social to $newLast (y/n)? "
                    read conf
                    if [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; then
                        echo "Invalid Input"
                    fi
                done;;
            2)
                echo -n 'Enter the new Last Name: '
                read newFirst
                while [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; do
                    echo -n "Are you sure you want to change the First Name of $social to $newFirst (y/n)? "
                    read conf
                    if [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; then
                        echo "Invalid Input"
                    fi
                done;;
            3)
                echo -n 'Enter the new DOB: '
                read newDate
                while [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; do
                    echo -n "Are you sure you want to change the DOB of $social to $newDate (y/n)? "
                    read conf
                    if [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; then
                        echo "Invalid Input"
                    fi
                done;;
            4)
                echo -n 'Enter the new Salary: '
                read newSal
                while [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; do
                    echo -n "Are you sure you want to change the salary of $social to $newSal (y/n)? "
                    read conf
                    if [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; then
                        echo "Invalid Input"
                    fi
                done;;
            *)
                echo 'Invalid input';;
        esac
    done
    echo '-------------------------------'
}

function retrieve {
    search=0
    while [ "$criteria" -ne 1 ] && [ "$criteria" -ne 2 ] && [ "$criteria" -ne 3 ] && [ "$criteria" -ne 4 ]; do
        echo '1. SSN'
        echo '2. Last Name'
        echo '3. First Name'
        echo '4. Salary'
        echo -n 'Choose from the following criteria: '
        read criteria
        echo '-------------------------------'
        case $criteria in
            1)
                echo -n 'Enter SSN: '
                read search;;
            2)
                echo -n 'Enter Last Name: '
                read search;;
            3)
                echo -n 'Enter First Name: '
                read search ;;
            4)
                echo -n 'Enter Salary: '
                read search ;;
            *)
                echo 'Invalid Entry';;
        esac
        echo '-------------------------------'
    done
}

function printDatabase {
    cat $file
    echo '-------------------------------'
}

while [ "$option" != 'X' ] && [ "$option" != 'x' ]
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
