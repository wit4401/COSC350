# Task 1
Refer to instructor’s lecture notes to implement a C program to catch ctrl-C and alarm signal. Run it to see how it behaves. 
# Task 2
Write a complete C program in which a child process write a message "Hi, Mom" to a file named foo. The parent process reads the message and prints it to standard output “My son said Hi Mom”. The part of message “Hi Mom” get from the file foo. Assume that all system calls succeed (no need to error check). Use only low-level file operations (fork, wait, open, close, read, write, lseek). You must make sure a child process terminate first.
# Task 3
Write a complete C program in which two chidren processes send signal to the parent. The first child send message SIGUSR1 to the parent and the parent process reponse by writing message “Hi Honey! Anything wrong?”. The second child send message SIGUSR2 to the parent and the parent response by writing message “Do you make trouble again? ”.
# Task 4
Write a complete C program that demonstrates how you can block and unblock signals. Your program will have two loops, each of which simply prints the integers from 1 to 5 at 1 second intervals. During the first loop, SIGINT and SIGQUIT are blocked. During the second loop, only SIGINT is blocked. While the program is running, you can try ^C and/or ^\ to see if they are blocked as expected.
* The signal SIGINT is usually bound to ^C by the terminal driver. The SIGINT signal terminates the program by default.
* The signal SIGQUIT is usually bound to ^\ by the terminal driver. The signal SIGQUIT by default causes the program to terminate and creates a core file 
