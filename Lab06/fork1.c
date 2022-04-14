/*********************
|    Lab 6 Task 2    |
|    Will Townsend   |
|    April  2022     |
*********************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void ChildProcess(int Nc,int Tc);
void ParentProcess(int Np,int Tp); 

void main(int argc,char *argv[]){
    if(argc!=5){
        puts("Please enter 4 values!");
        exit(1);
    }
    pid_t pid, ppid;
    pid = fork(); /* create a child */
    if (pid == 0) /* means a child process*/
        ChildProcess(atoi(argv[1]),atoi(argv[3]));
    else
        ParentProcess(atoi(argv[2]),atoi(argv[4]));
}
void ChildProcess(int Nc,int Tc){
    int i;
    for (i = 1; i <= Nc; i++){
        printf(" This line is from child process value = %d\n", i);
        sleep(Tc);
    }
    printf(" *** Child process is done ***\n");
}
void ParentProcess(int Np,int Tp){
    int i;
    for (i = 1; i <= Np; i++){
        printf("This line is from parent process value = %d\n", i);
        sleep(Tp);
    }
    printf("*** Parent is done ***\n");
}
