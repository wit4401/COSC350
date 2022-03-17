/*********************
|    Lab 5 Task 2    |
|    Will Townsend   |
|    March  2022     |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utmp.h>

int openUtmpFile(){
    int fd;
    if((fd=open("/var/run/utmp",O_RDONLY))==-1){
        puts("Could not open file.");
        exit(1);
    }
    return fd;
}

int main(){
    printf("File descriptor for umpt.h: %d\n",openUtmpFile());
    exit(0);
}
