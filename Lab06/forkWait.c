/*********************
|    Lab 6 Task 3    |
|    Will Townsend   |
|    April  2022     |
*********************/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
    if(argc!=5){
        puts("Please enter 4 arguements!");
        exit(1);
    }
    pid_t pid;
    char *message;
    int n;
    int sec;
    printf("fork program starting\n");
    pid = fork();
    switch(pid){
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            message = "This is the child";
            n = atoi(argv[1]);
            sec=atoi(argv[3]);
            break;
        default:
            message = "This is the parent";
            n = atoi(argv[2]);
            sec=atoi(argv[4]);
            wait(NULL);
            break;
    }
    for(; n > 0; n--) {
        puts(message);
        sleep(sec);
    }
    exit(0);
}

