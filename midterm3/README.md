# Midterm 3 Programs
## Problem 1
Write two separate C programs: parent program (parent.c) and child program (child.c):
* child.c takes three command line arguments: the first one is a character (+ or -) followed by two integers. Depending on the value of the first parameter, child.c will perform addition (if + is passed in) or minus (if - is passed in) and display the result of the calculation.
* parent.c reads in two integers from the standard input and forks two child processes to run child.c. The first child process will run child.c with '+' and the two integers read in from the standard input.The second child process will run child.c with '-' and the two integers read in from the standard input.
## Problem 2
Write a C program to act as the following:
* The child process sends the message "Hi, Mom" over a pipe to its parent process. The parent process reads the message from the pipe and prints it out to the standard input as "my child said" and the message fom the child, in this case, "Hi mom". Then parent process senddss the message "I love you" over a pipe to its child.
* The child process reads the message and prints it to the standard output as "My mom said" and then the message from the parent process, in this case, "I love you".
## Problem 3
Write two separate C programs: parent program (parent.c) and child program (child.c):
* The parent forks a child process to read messages from a pipe. The parents repeats this process infinitely: has an alarm clock that set of every 10 seconds. Whenever the alarm sets off, the parent writes a message "I am here, baby\n" to a pipe and sends a SIGUSR1 signal to its child.
* The child program, used by the above parent program, always waits for SIGUSR1. When SIGUSR1 arrives, the child reads the parent's message from the pipe and displays it on the screen and goes back to wait for more SIGUSR1 signals.
## Problem 4
Write a C program to create three threads and each thread runs its own function fun1, fun2, and fun3 respectively.
* The first thread gets a command line integer value (from argv[1]) and multiply that value by 10.
* The second thread takes the result of the first thread and add 20 to it.
* The third thread takes the result of the second thread and divides it by 4.
* Then, the original program (main thread) prints the final results returned from each thread in the end. 
