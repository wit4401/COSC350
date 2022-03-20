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
	int fd=openUtmpFile();
	int rbyte;
	char buff[1028];
    printf("File descriptor for umpt.h: %d\n",fd);
    while((rbyte=read(fd,buff,sizeof(buff)))>0)
    	write(1,buff,rbyte);
    //printf("Number of users: %d\n",userCount);
    exit(0);
}
