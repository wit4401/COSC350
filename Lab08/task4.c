/*********************
|    Lab 8 Task 4    |
|    Will Townsend   |
|      May 2022      |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>

FILE *pFd,*cFd;

int main(){
    char shellStr[1024];
    char fileName[1024];
    pid_t pid;

    printf("Enter a shell command: ");
    scanf("%s",shellStr);
    printf("Enter a file name: ");
    scanf("%s",fileName);
    
    pid=fork();
    if(pid>0){
        pFd=popen(shellStr,"w");
        fwrite(fileName,sizeof(char),strlen(fileName),pFd);

    }
    else if (pid==0){
        cFd=popen(shellStr,"r");
    }
    else{
        puts("fork() error");
        exit(1);
    }
    exit(0);
}
