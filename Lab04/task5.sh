#Lecture Slide Code
foo=10
x=foo
y=\$$x #it is same as y=‘$’$x
echo $y
foo=10
x=foo
eval y=\$$x
echo $y

#Experimental Code
echo -n "Please Enter a number: "
read num;
ref=num
eval y=\$$ref
for i in $(seq 1 $y);do
    echo -n "$i "
done
echo

exit 0
