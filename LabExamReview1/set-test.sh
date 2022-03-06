#!/bin/sh
# script "set-test1.sh"
# Invoke this script with three command line parameters,
# for example, "./set-test one two three".
echo
echo "Positional parameters before set \`uname -a\` :"
echo "Command-line argument #1 = $1"
echo "Command-line argument #2 = $2"
echo "Command-line argument #3 = $3"
set `uname -a` # Sets the positional parameters to the output
# of the command `uname -a`
# The output of `uname -a`
# Linux sophie-wang 5.4.0-100-generic #113-Ubuntu SMP Thu Feb 3 18:43:29 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux
echo $_ # last positional parameter
# Flags set in script.
echo "Positional parameters after set \`uname -a\` :"
# $1, $2, $3, etc. reinitialized to result of `uname -a`
i=1
for ARG in " $@ "; do
    echo "Field " $i " of 'uname -a' = $ARG"
    let i++
done
exit 0 
