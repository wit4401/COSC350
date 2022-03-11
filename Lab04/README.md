# Task 1
### In Task 8 in Lab 3, you wrote a program to encode a file with character to a file with ASCII code number. Write decoding program which covert output of Task 8 in Lab 3 to original input file.
# Task 2
### Write a C main function that takes one command-line argument, the name of an input file. The input file contains exactly one integer spread out over a single line of up to 80 characters. For example, the integer 3579 is embedded in the line az3mqrm5t?7!z*&gqmzt9v. Your program uses system calls to do the following:
#### a. open and read the input file, accumulating the discovered digit characters into a character array (string).
#### b. Convert the string to an integer./taskdr (do not use atoi function).
#### c. Add 10 to the integer
#### d. convert the sum back to a string (using function convIntToStr)
#### e. make a system call to write the string to standard output.
# Task 3
### Write a C-function int palind(int fd1, int fd2) that takes two independent file descriptors fd1 and fd2 that are already opened to the same file. The function palind() uses lseek to scan the file and returns 1 if the file contains a palindrome (reads the same forward and reverse) and 0 if not. You may assume that the file is well-formed and contains just lower-case alphabetic characters on a single line. You also need write a main function to test your palind() function works properly. The main function accept a file name as a argument. The main() function open the file once and create duplicate file descriptor. And call the function palind() to check whether the file contains palindrome or not.
# Task 4 (hello.c)
### Write a simple program called hello.c and compile it and create executable file named hello. Write a C program for sequence of following task.
#### By using system call, build following directory structure (\home\dir1 and \home\dir2\dir21).
#### By using system calls, copy hello file under ~/Dir2/Dir21/
#### By using system calls, make a symbolic link named toDir21 to directory Dir21
#### By using system calls, make a symbolic link named toHello to executable file ~/Dir21/hello
# Task 5 (MyMv.c)
### Write your own mv named MyMv: By using bash command mv, you can move a file from current directory to another directory. Write your own mv called MyMv by using system calls link() and unlink(). Your program named MyMv can move a file from a current directory to a directory. Your program receives two arguments: file name and path to a directory where the file need to move, or file name and path to directory with a file name. If the second argument is a directory, move a file to the directory. If the second argument is not a directory, move file to directory as a file name.
