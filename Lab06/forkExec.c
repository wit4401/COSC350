/*********************
|    Lab 6 Task 4    |
|      (main)        |
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
            message="This is the child";
            execl("/mnt/linuxlab/home/wtownsend2/COSC350/Lab06/child",message,argv[1],argv[3],NULL);
            break;
        default:
            message = "This is the parent";
            n = atoi(argv[2]);
            sec=atoi(argv[4]);
            wait(NULL);
            for(; n > 0; n--) {
                printf("%s. pid=%d\n",message,getpid());
                sleep(sec);
            }
            break;
    }
    exit(0);
}
