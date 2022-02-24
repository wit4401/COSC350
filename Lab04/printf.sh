#!/bin/sh
# printf.sh
#Print the decimal number 5 followed by a newline (\n)
printf "%d\n" 5
#Print as float (default 6 decimal places)
printf "%f\n" 5
#Print text followed by variable $USER
printf "Hello, $USER.\n\n"
#Display variables distance=15 with 5 spaces aligned to
distance=15
printf "Distance is %5d Miles\n" $distance
#Use \n anywhere to start a new line:
printf "Two separate\n lines \n"
#Print decimal numbers interspersed with text
printf "There are %d orders valued at over %d euros.\n" 64 1500
#Convert a hex number to decimal
printf "%d\n " 0xF
#Convert a decimal number to Hex
printf "0x%X\n " 15
#Convert a decimal number to Octal
printf "0%o\n " 8
#Convert an Octal number to decimal
printf "%d\n " 010
exit 0
