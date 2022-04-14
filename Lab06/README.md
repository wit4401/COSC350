# Task 1
* Write your own getenv() function called mygetenv() function which has same syntax and
semantics.
* Write a simple C program to show your mygetenv() function works well.
# Task 2
* Copy fork1.c from BLP 4th edition, page 474.
* Compile and run it to be sure you understand what it does.
* Modify your fork1.c to take four command-line arguments:
  * Nc - number of iterations for child process
  * Np - number of iterations for parent process
  * Tc - sleep time for child process
  * Tp - sleep time for parent process
  * Then, modify the code accordingly.
* Run the program as fork1 5 3 1 1. You should get the same result as running the original
version.
* Run the program with the following values (and any other values you find interesting): 
# Task 3
* Copy your modified fork1.c to a file named forkWait.c.
* Modify forkWait.c so the parent process waits for the child to finish. Use the code from BLP 4th edition in page 475 (page 458 in 3rd edition), for the wait portion.
* Print your modified forkWait.c to hand in.
* Run your forkWait with Nc = 5, Np = 3, Tc = 1, and Tp = 1.
* Briefly describe how your result differs from the original program in Task 2. Explain. 
# Task 4
This task forks a child process and uses exec to replace its process image with another image. It's
very similar to Task 3, but the child process is implemented as a separate program.
* Copy forkWait.c from Task 4 to a file named forkExec.c
* Modify forkExec.c so the child process image is replaced by the image of a program named child. Use one of the exec family of functions to do this.
* Write child.c to do the same thing as the child process did in Task 4.
  * The child should give its pid each time it prints the message.
  * The parent should give its pid each time it prints the message.
  * The child program should take three command-line arguments, the message, Nc, and Tc.
  * To get an interesting exit status from the child, have it return 37, rather than 0. 
# Task 5
Write a C program such that receive an input file name as an argument and open the file as inputs. And then create a child process. Input file must open only one time and the file descriptor is shared by parent and child process. Both the parent and the child read a byte at a time from the input file and write output to independent files (parent.txt for parent output, child.txt for child output). The parent process collect numeric characters and child collect non-numberic characters. Without any form of synchronization, parent and child process will create wrong output files.
* Modify the previous program and try to synchronize and get correct outputs for each process.

Note)
* Do not open the input file twice for synchronization.
* Define your own function to check numeric character.
* Do not use vfork(), sleep(), wait() or waitpid() for synchronization.
* Check all possible errors for system calls
