/*********************
|    Lab 7 Task 3    |
|    Will Townsend   |
|    April  2022     |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>

void sig_handler(int signo){
    if(signo==SIGUSR1)//response to the first child
        puts("Hi, Honey. Anything wrong?");
    if(signo==SIGUSR2)//response to the second child
        puts("Did you make trouble again?");
}

int main(){
    pid_t pid1,pid2;
    pid1=fork();//creates the first child
    switch (pid1){
        case -1://error case
            puts("fork error");
            exit(1);
        case 0://first child process
            kill(getppid(),SIGUSR1);
            _exit(0);
        default://parent process action 1
            signal(SIGUSR1,sig_handler);
            pause();
    }
    pid2=fork(); //creates the second child
    switch(pid2){
        case -1://error case
            puts("fork error");
            exit(2);
        case 0:  //second child process
            kill(getppid(),SIGUSR2);
            _exit(0);
        default://parent process action 2 
            signal(SIGUSR2,sig_handler);
            pause();
            exit(0);
    }
    
}
