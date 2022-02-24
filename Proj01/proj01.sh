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
    local len=11;
    touch $file
    while [ "$len" -ne 9 ] || [ -z $social ] || grep -q "$social" $file;do
        echo -n 'Enter SSN (Do not include "-"): '
        read social
        
        len=`expr length $social`
        three=`expr substr $social 1 3`
        two=`expr substr $social 4 2`
        four=`expr substr $social 6 4`
        social="$three-$two-$four"
        
        if `grep -q "$social" $file`;then
            echo "SSN Exists!"
        elif [ $len -ne 9 ];then
            echo "Please Enter 9 digits."
        fi
    done
    
    len=11;
    while [ -z $first ] || [ "$len" -gt 10 ];do
        echo -n 'Enter First Name: '
        read first
        len=`expr length $first`
        if [ $len -gt 10 ];then
            echo "Only <11 characters"
        fi
    done
    
    len=11;
    while [ -z $last ] || [ "$len" -gt 10 ];do
        echo -n 'Enter Last Name: '
        read last
        len=`expr length $last`
        if [ $len -gt 10 ];then
            echo "Only <11 characters"
        fi
    done
    
    len=11;
    while [ -z $birth ] || [ $len -ne 8 ];do
        echo -n 'Enter Birthday (MMDDYYYY): '
        read birth
        len=`expr length $birth`
        if [ $len -ne 8 ];then
            echo "8 digits are required!"
        fi
    done
    month=`expr substr $birth 1 2`
    day=`expr substr $birth 3 2`
    year=`expr substr $birth 5 4`
    birth="$month-$day-$year"
    
    local salary=-1
    while [ "$salary" -lt 0 ];do
        echo -n 'Enter Salary: '
        read salary 
        if [ "$salary" -lt 0 ];then
            echo "Salary must be positive!"
        fi
    done
    echo "$first $last $social $birth $salary">>$file
    echo '-------------------------------'
}

function delete {
    if [ -f $file ];then
        social='xx-xxx-xxxx'
        delete='m'
        echo -n 'Enter SSN of employee (include "-"): '
        read social
        local check=`grep $social $file`
        if [ -z "$check" ];then
            echo "SSN not found!"
            echo '-------------------------------'
            return 0
        fi
        while [ "$delete" != 'n' ] && [ "$delete" != 'y' ]; do
            echo -n "Are you sure you want to delete $social (y/n)? "
            read delete
            if [ "$delete" != 'n' ] && [ "$delete" != 'y' ]; then
                echo 'Invalid Input'
            fi
        done
    else
        echo "Add to the Database before deletion!"
    fi
    echo '-------------------------------'
}

function modify {
    if [ ! -f $file ];then
        echo "Add to the Database before modifying!"
        echo '-------------------------------'
        return 0
    fi
    social='xx-xxx-xxxx'
    newLast='0'
    newFirst='0'
    newDate='0'
    newSal='0'
    echo -n 'Please Enter the SSN of the employee to be modified: '
    read social;
    while [ "$search" -ne 1 ] || [ "$search" -ne 2 ] || [ "$search" -ne 3 ] || [ "$search" -ne 4 ]; do
        echo '1. Last Name'
        echo '2. First Name'
        echo '3. DOB'
        echo '4. Salary'
        echo -n 'Please sel\3[40;37mect a value: '
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
    if [ ! -f $file ];then
        echo "Add to the Database before retrieving!"
        echo '-------------------------------'
        return 0
    fi
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
    if [ ! -f $file ];then
        echo "Nothing to Display!"
        echo '-------------------------------'
        return 0
    fi
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
