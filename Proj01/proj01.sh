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
    local confir='m';
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
    while [ "$confir" != 'n' ] && [ "$confir" != 'y' ]; do
        echo
        echo  "Are you sure you want to insert the following data?"
        echo "$first $last $social $birth $salary"
        echo -n "(y/n): "
        read confir
        if [ "$confir" != 'n' ] && [ "$confir" != 'y' ]; then
            echo
            echo 'Invalid Input'
        fi
    done
    if [ "$confir" == y ];then
        echo "$first $last $social $birth $salary">>$file
    else
        echo
        echo "Data not inserted."
    fi
    echo
    echo '-------------------------------'
}

function delete {
    if [ -f $file ];then
        social='xx-xxx-xxxx'
        delete='m'
        echo '------------------------------------------------------'
        echo -n 'Enter SSN of employee (include "-"): '
        read social
        local check=`grep $social $file`
        if [ -z "$check" ];then
            echo "SSN not found!"
            echo '------------------------------------------------------'
            return 0
        fi
        while [ "$delete" != 'n' ] && [ "$delete" != 'y' ]; do
            echo -n "Are you sure you want to delete $social (y/n)? "
            read delete
            if [ "$delete" != 'n' ] && [ "$delete" != 'y' ]; then
                echo 'Invalid Input'
            fi
        done
        if [ "$delete" == 'y' ];then
            sed -i "/$social/d" $file
        fi
    else
        echo "Add to the Database before deletion!"
    fi
    echo '------------------------------------------------------'
}

function modify {
    if [ ! -f $file ];then
        echo "Add to the Database before modifying!"
        echo '-------------------------------'
        return 0
    fi
    local social=0
    local newLast=0
    local newFirst=0
    local newDate=0
    local newSal=-1
    search=0
    echo -n 'Please Enter the SSN of the employee to be modified: '
    read social;
    if grep -q $social $file;then
       echo `grep $social $file`
    else
        echo "SSN not found!"
        echo '-------------------------------'
        return -1
    fi
    echo
    while [ "$search" -ne 1 ] && [ "$search" -ne 2 ] && [ "$search" -ne 3 ] && [ "$search" -ne 4 ]; do
        echo '1. Last Name'
        echo '2. First Name'
        echo '3. DOB'
        echo '4. Salary'
        echo -n 'Please select a value: '
        read search
        echo
        case $search in
            1)
                len=11;
                while [ "$len" -gt 10 ];do
                    echo -n 'Enter Last Name: '
                    read newLast
                    len=`expr length $newLast`
                    if [ $len -gt 10 ];then
                        echo "Only <11 characters"
                    fi
                done
                while [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; do
                    echo -n "Are you sure you want to change the Last Name of $social to $newLast (y/n)? "
                    read conf
                    if [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; then
                        echo "Invalid Input"
                    fi
                done;;
            2)
                len=11;
                while [ "$len" -gt 10 ];do
                    echo -n 'Enter First Name: '
                    read newFirst
                    len=`expr length $newFirst`
                    if [ $len -gt 10 ];then
                        echo "Only <11 characters"
                    fi
                done
                while [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; do
                    echo -n "Are you sure you want to change the First Name of $social to $newFirst (y/n)? "
                    read conf
                    if [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; then
                        echo "Invalid Input"
                    fi
                done;;
            3)
                len=11;
                while [ $len -ne 8 ];do
                    echo -n 'Enter Birthday (MMDDYYYY): '
                    read newDate
                    len=`expr length $newDate`
                    if [ $len -ne 8 ];then
                        echo "8 digits are required!"
                    fi
                done
                month=`expr substr $birth 1 2`
                day=`expr substr $birth 3 2`
                year=`expr substr $birth 5 4`
                newDate="$month-$day-$year"
                while [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; do
                    echo -n "Are you sure you want to change the DOB of $social to $newDate (y/n)? "
                    read conf
                    if [ "$conf" != 'y' ] && [ "$conf" != 'n' ]; then
                        echo "Invalid Input"
                    fi
                done;;
            4)
                while [ "$newSal" -lt 0 ];do
                    echo -n 'Enter Salary: '
                    read newSal 
                    if [ "$newSal" -lt 0 ];then
                        echo "Salary must be positive!"
                    fi
                done
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
    echo
    echo '-------------------------------'
}

function retrieve {
    if [ ! -f $file ];then
        echo "Add to the Database before retrieving!"
        echo '---------------------------------------'
        return 0
    fi
    search=0
    criteria=0
    while [ "$criteria" -ne 1 ] && [ "$criteria" -ne 2 ] && [ "$criteria" -ne 3 ] && [ "$criteria" -ne 4 ]; do
        echo '----------------------------------------'
        echo '1. SSN'
        echo '2. Last Name'
        echo '3. First Name'
        echo '4. Salary'
        echo -n 'Choose from the following criteria: '
        read criteria
        echo '----------------------------------------'
        local len=11
        case $criteria in
            1)
                echo -n 'Enter SSN: '
                read search
                if `grep -q $search $file`;then
                    grep $search $file|sort -k 1
                else
                    echo 'No data exists!'
                fi
                ;;
            2)
                echo -n 'Enter Last Name: '
                read search
                if `grep -q $search $file`;then
                    grep $search $file|sort -k 3
                else
                    echo 'No data exists!'
                fi;;
            3)
                echo -n 'Enter First Name: '
                read search
                if `grep -q $search $file`;then
                    grep $search $file|sort -k 2
                else
                    echo 'No data exists!'
                fi;;
            4)
                echo -n 'Enter Salary: '
                read search
                if `grep -q $search $file`;then
                    grep $search $file|sort -k 5
                else
                    echo 'No data exists!'
                fi;;
            *)
                echo 'Invalid Entry';;
        esac
        echo '-------------------------------'
    done
}

function printDatabase {
    if [ ! -f $file ];then
        echo '-------------------------------'
        echo "Nothing to Display!"
        echo '-------------------------------'
        return 0
    fi
    echo '------------------------------------------------'
    cat $file
    echo '------------------------------------------------'
}

while [ "$option" != 'X' ] && [ "$option" != 'x' ]
do 
    DisplayMenu
    read option
    case $option in
        a | A) insert ;;
        b | B) modify ;;
        c | C) delete ;;
        d | D) retrieve ;;
        e | E) printDatabase ;;
        x | X) echo 'Exiting Program...';;
        *)
            echo '-------------------------------'
            echo 'Invalid Input'
            echo '-------------------------------';;
    esac
done
exit 0
