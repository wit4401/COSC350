#!/bin/bash
file=employee.db
option='A'
criteria=0

function colorScheme {
    case $1 in
        Black_white)
            echo -n -e "\e[40;37m";;
        Black_green)
            echo -n -e "\e[40;32m";;
        Black_cyan)
            echo -n -e "\e[40;36m";;
        Black_red)
            echo -n -e "\e[40;31m";;
        Black_purple)
            echo -n -e "\e[40;35m";;
    esac
}

function DisplayMenu {
    echo 'Employee Database Menu'
    echo '-------------------------------'
    echo 'A. Insert'
    echo 'B. Modify'
    echo 'C. Delete'
    echo 'D. Retrieve'
    echo 'E. Display'
    echo 'F. Help'
    echo 'X. Exit Program'
    echo -n 'Please Select an Option: '
}

function insert {
    echo
    local len=11;
    local confir='m';
    touch $file
    while [ "$len" -ne 9 ] || [ -z "$social" ] || grep -q "$social" $file;do
        colorScheme Black_green
        echo -n 'Enter SSN (Do not include "-"): '
        read social
        
        len=`expr length $social`
        three=`expr substr $social 1 3`
        two=`expr substr $social 4 2`
        four=`expr substr $social 6 4`
        social="$three-$two-$four"
        
        if `grep -q "$social" $file`;then
            colorScheme Black_red
            echo "SSN Exists!"
        elif [ "$len" -ne 9 ];then
            colorScheme Black_red
            echo "Please Enter 9 digits."
        fi
    done
    
    len=11;
    while [ -z $first ] || [ "$len" -gt 10 ];do
        colorScheme Black_green
        echo -n 'Enter First Name: '
        read first
        len=`expr length $first`
        if [ "$len" -gt 10 ];then
            colorScheme Black_red
            echo "Only <11 characters"
        fi
    done
    
    len=11;
    while [ -z $last ] || [ "$len" -gt 10 ];do
        colorScheme Black_green
        echo -n 'Enter Last Name: '
        read last
        len=`expr length $last`
        if [ "$len" -gt 10 ];then
            colorScheme Black_red
            echo "Only <11 characters"
        fi
    done
    
    len=11;
    while [ -z $birth ] || [ "$len" -ne 8 ];do
        colorScheme Black_green
        echo -n 'Enter Birthday (MMDDYYYY): '
        read birth
        len=`expr length $birth`
        if [ "$len" -ne 8 ];then
            colorScheme Black_red
            echo "8 digits are required!"
        fi
    done
    local month=`expr substr $birth 1 2`
    local day=`expr substr $birth 3 2`
    local year=`expr substr $birth 5 4`
    local birth="$month-$day-$year"
    
    local salary=-1
    while [ "$salary" -lt 0 ];do
        colorScheme Black_green
        echo -n 'Enter Salary: '
        read salary 
        if [ "$salary" -lt 0 ];then
            colorScheme Black_red
            echo "Salary must be positive!"
        fi
    done
    while [ "$confir" != 'n' ] && [ "$confir" != 'y' ]; do
        colorScheme Black_green
        echo
        echo  "Are you sure you want to insert the following data:"
        echo "$first $last $social $birth $salary"
        echo -n "(y/n): "
        read confir
        if [ "$confir" != 'n' ] && [ "$confir" != 'y' ]; then
            colorScheme Black_red
            echo
            echo 'Invalid Input'
        fi
    done
    echo
    if [ "$confir" == y ];then
        printf "%-10s" $first $last>>$file 
        printf "%-12s" $social $birth $salary>>$file
        echo>>$file
        echo "Data inserted Sucessfully!"
    else
        colorScheme Black_red
        echo "Data not inserted."
    fi
    colorScheme Black_green
        echo '-----------------------------------------------------'
}

function delete {
    if [ -f $file ];then
        local social='xx-xxx-xxxx'
        local delete='m'
        local len=0;
        echo
        while [ "$len" -ne 11 ];do
            colorScheme Black_green
            echo -n 'Enter SSN of employee (include "-"): '
            read social
            len=`expr length $social`
            if [ "$len" -ne 11 ];then
                colorScheme Black_red
                echo "Invalid Input"
            fi
        done
        local check=`grep $social $file`;
        if [ ! "$check" ];then
            colorScheme Black_red
            echo "Employee not found"
            return -1;
        else
            colorScheme Black_cyan
            echo '-------------------------------------------------------'
            printf '%-10s' First Last
            printf '%-12s' SSN DOB Salary
            echo
            printf "%-10s" Name Name
            echo
            echo '-------------------------------------------------------'
            grep $social $file
            echo '-------------------------------------------------------'
        fi
        colorScheme Black_red
        while [ "$delete" != 'n' ] && [ "$delete" != 'y' ]; do
            echo -n "Are you sure you want to delete this employee (y/n)? "
            read delete
            if [ "$delete" != 'n' ] && [ "$delete" != 'y' ]; then
                echo 'Invalid Input'
            fi
        done
        if [ "$delete" == 'y' ];then
            sed -i "/$social/d" $file
            echo "Employee Deleted"
        else
            colorScheme Black_green
            echo "Employee Not Deleted!"
        fi
        colorScheme Black_green
        echo '-------------------------------------------------------'
    else
        colorScheme Black_red
        echo "Add to the Database before deletion!"
    fi
}

function modify {
    if [ ! -f $file ];then
        colorScheme Black_red
        echo "Add to the Database before modifying!"
        echo '--------------------------------------'
        return 0
    fi
    local social=0
    local newLast=0
    local newFirst=0
    local newDate=0
    local newSal=-1
    local confir='m'
    local len=0
    
    while [ "$len" -ne 11 ];do
        colorScheme Black_green
        echo -n 'Please Enter the SSN of the employee to be modified (include "-"): '
        read social
        len=`expr length $social`
        if [ "$len" -ne 11 ];then
            colorScheme Black_red
            echo "Invalid Input"
        fi
    done
    echo '--------------------------------------------------------------------------------'
    if grep -q $social $file;then
        colorScheme Black_cyan
        echo '-------------------------------------------------------'
        printf '%-10s' First Last
        printf '%-12s' SSN DOB Salary
        echo
        printf "%-10s" Name Name
        echo
        echo '-------------------------------------------------------'
        grep $social $file
        echo '-------------------------------------------------------'
    else
        colorScheme Black_red
        echo "SSN not found!"
        echo '-------------------------------'
        return -1
    fi
    colorScheme Black_green
    len=11;
    while [ "$len" -gt 10 ];do
        colorScheme Black_green
        echo -n 'Enter New First Name: '
        read newFirst
        len=`expr length $newFirst`
        if [ "$len" -gt 10 ];then
            colorScheme Black_red
            echo "Only <11 characters"
        fi
    done
    
    len=11;
    while [ "$len" -gt 10 ];do
        colorScheme Black_green
        echo -n 'Enter New Last Name: '
        read newLast
        len=`expr length $newLast`
        if [ "$len" -gt 10 ];then
            colorScheme Black_red
            echo "Only <11 characters"
        fi
    done
    
    len=11;
    while [ "$len" -ne 8 ];do
        colorScheme Black_green
        echo -n 'Enter New Birthdate (MMDDYYYY): '
        read newDate
        len=`expr length $newDate`
        if [ "$len" -ne 8 ];then
            colorScheme Black_red
            echo "8 digits are required!"
        fi
    done
    local month=`expr substr $newDate 1 2`
    local day=`expr substr $newDate 3 2`
    local year=`expr substr $newDate 5 4`
    local newDate="$month-$day-$year"
    
    while [ "$newSal" -lt 0 ];do
        colorScheme Black_green
        echo -n 'Enter New Salary: '
        read newSal 
        if [ "$newSal" -lt 0 ];then
            colorScheme Black_red
            echo "Salary must be positive!"
        fi
    done
    while [ "$confir" != 'n' ] && [ "$confir" != 'y' ]; do
        colorScheme Black_green
        echo
        echo  "Are you sure you want to update the employee as shown:"
        echo "$newFirst $newLast $social $newDate $newSal"
        echo -n "(y/n): "
        read confir
        if [ "$confir" != 'n' ] && [ "$confir" != 'y' ]; then
            colorScheme Black_red
            echo
            echo 'Invalid Input'
        fi
    done
    echo
    if [ "$confir" == y ];then
        sed -i "/$social/d" $file 
        printf "%-10s" $newFirst $newLast>>$file 
        printf "%-12s" $social $newDate $newSal>>$file
        echo>>$file
        echo "Data updated Sucessfully!"
        echo '--------------------------------------------------------------------------------'
    else
        colorScheme Black_red
        echo "Data was not updated."
        colorScheme Black_green
        echo '--------------------------------------------------------------------------------'
    fi
}

function retrieve {
    if [ ! -f $file ];then
        colorScheme Black_red
        echo "Add to the Database before retrieving!"
        echo '---------------------------------------'
        return 0
    fi
    local search=0
    local criteria=0
    while [ "$criteria" -ne 1 ] && [ "$criteria" -ne 2 ] && [ "$criteria" -ne 3 ] && [ "$criteria" -ne 4 ]; do
        echo
        echo '1. SSN'
        echo '2. Last Name'
        echo '3. First Name'
        echo '4. Salary'
        echo -n 'Choose from the following criteria: '
        read criteria
        local len=12
        case $criteria in
            1)
                while [ "$len" -ne 11 ];do
                    colorScheme Black_green
                    echo -n 'Enter SSN (Include "-"): '
                    read search
                    len=`expr length $search`
                    if [ "$len" -ne 11 ];then
                        colorScheme Black_red
                        echo "Invaild Input!"
                    fi
                done
                colorScheme Black_cyan
                echo '-------------------------------------------------------'
                printf '%-10s' First Last
                printf '%-12s' SSN DOB Salary
                echo
                printf "%-10s" Name Name
                echo
                echo '-------------------------------------------------------'
                grep $search $file
                echo '-------------------------------------------------------'
                ;;
            2)
                echo -n 'Enter Last Name: '
                read search
                colorScheme Black_cyan
                echo '-------------------------------------------------------'
                printf '%-10s' First Last
                printf '%-12s' SSN DOB Salary
                echo
                printf "%-10s" Name Name
                echo
                echo '-------------------------------------------------------'
                awk -vcol="2" -vsearch="$search" '$col ~ search' $file|sort -n -k2
                echo '-------------------------------------------------------';;
            3)
                echo -n 'Enter First Name: '
                read search
                colorScheme Black_cyan
                echo '-------------------------------------------------------'
                printf '%-10s' First Last
                printf '%-12s' SSN DOB Salary
                echo
                printf "%-10s" Name Name
                echo
                echo '-------------------------------------------------------'
                awk -vcol="1" -vsearch="$search" '$col ~ search' $file|sort -n -k1
                echo '-------------------------------------------------------';;
            4)
                echo -n 'Enter Salary: '
                read search
                colorScheme Black_cyan
                echo '-------------------------------------------------------'
                printf '%-10s' First Last
                printf '%-12s' SSN DOB Salary
                echo
                printf "%-10s" Name Name
                echo
                echo '-------------------------------------------------------'
                awk -vcol="5" -vsearch="$search" '$col ~ search' $file|sort -n -k5
                echo '-------------------------------------------------------';;
            *)
                colorScheme Black_red
                echo 'Invalid Entry';;
        esac
    done
}

function printDatabase {
    if [ ! -f $file ];then
        colorScheme Black_red
        echo '-------------------------------'
        echo "Nothing to Display!"
        echo '-------------------------------'
        return 0
    fi
    colorScheme Black_cyan
    echo '-------------------------------------------------------'
    printf '%-10s' First Last 
    printf '%-12s' SSN DOB Salary
    echo
    printf "%-10s" Name Name
    echo
    echo '-------------------------------------------------------'
    cat $file
    echo '-------------------------------------------------------'
}

function helpInfo {
    colorScheme Black_purple
    echo '--------------------------------------------------------'
    echo 'Welcome to the Employee Database Simulation via Bash!'
    echo 'Here you can insert, delete, modify, and search for'
    echo 'employees within the database via a file. A breif'
    echo 'description of each menu item is below happy browsing!'
    echo
    echo 'Basic Info: Just follow the button prompts to navigate'
    echo 'the menu and enter/modify/delete the data.'
    echo
    echo 'Insert: This menu lets you enter an employee into the'
    echo 'database with their first name, last name, social'
    echo 'security number, birthday, and salary.'
    echo
    echo 'Modify: This menu allows you to modify the data points'
    echo '(Last Name, First Name, DOB, or Salary) all at once'
    echo '(must know SSN of employee).'
    echo
    echo 'Delete: This menu allows us to delete employees.(Must'
    echo 'know SSN of employee)'
    echo
    echo 'Retrieve: This menu allow you to display certian'
    echo 'employees based on a single criteria and sorts them'
    echo 'via that criteria. Criteria includes SSN, first and'
    echo 'last name, and salary (Note: that the search is'
    echo 'case sensitive and displays anything with the string'
    echo 'of characters entered (SSN is an exception)'
    echo
    echo 'Display: Simple function that displays all employees'
    echo 'in the Database from last modified/added to most'
    echo 'recently modified/added'
    echo
    echo -n 'Please press enter to go back to the menu'
    read space
    echo '--------------------------------------------------------'
}

while [ "$option" != 'X' ] && [ "$option" != 'x' ]
do
    colorScheme Black_green
    echo '-------------------------------'
    DisplayMenu
    read option
    case $option in
        a | A) insert ;;
        b | B) modify ;;
        c | C) delete ;;
        d | D) retrieve ;;
        e | E) printDatabase ;;
        f | F) helpInfo;;
        x | X) echo 'Exiting Program...';;
        *)
            colorScheme Black_red
            echo '-------------------------------'
            echo 'Invalid Input'
            echo '-------------------------------';;
    esac
done
colorScheme Black_white
exit 0
