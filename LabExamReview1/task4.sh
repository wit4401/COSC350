#from lecture
for myloop in 1 2 3 4 5 
do
    echo "$myloop"
    if [ "$myloop" -eq 3 ]
    then
        break
    fi
done

for myloop in 1 2 3 4 5
do
    if [ "$myloop" -eq 3 ]
    then
    continue # Skip rest of loop iteration.
    fi
    echo "$myloop"
done

exit 0
