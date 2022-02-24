#!/bin/bash
# GlobalLocal.sh
# Global and local variables inside a function.
LocalGlobal ()
{
local loc_var=23 # Declared as local variable.
echo "\"loc_var\" in function = $loc_var"
global_var=999 #global variable
echo "\"global_var\" in function = $global_var"
}
LocalGlobal
echo "\"loc_var\" outside function = $loc_var"
echo "\"global_var\" outside function = $global_var"
exit 0
