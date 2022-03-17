# Task 1
###  Write your own mv named MyMv By using bash command mv, you can move a file from current directory to another directory. Write your own mv called MyMv by using system calls link() and unlink(). Your program named MyMv can move a file from a current directory to a directory. Your program receives two arguments: file name and path to a directory where the file need to move, or file name and path to directory with a file name. If the second argument is a directory, move a file to the directory. If the second argument is not a directory, move file to directory as a file name.
### <em>This is a reapt of task 5 in lab 4 since our time to complete it was extended. See lab 4 for the program.</em>
# Task 2
### Open the utmp file
#### a. Write a function named openUtmpFile that opens the utmp file and returns its file descriptor. If the file can't be opened, the function writes an error message and exits (thereby terminating the program). 
#### b. Call openUtmpFile in the main function. Compile your program to check for errors.
#### c. Add code in your main function to loop through the utmp file, reading each record. For each record, just print the user name. 
#### d. Add code in the loop to count the number of records that are USER_PROCESS records (logged-in users). When the loop is done, print the number of logged-in users found. Check your results for correctness
# Task 3
### Write your own asctime which returns string
#### a. Write your own function myasctime which operates exactly same as char *asctime(const struct tm *timeptr).
#### b. Write a C program to demonstrate your myasctime function
