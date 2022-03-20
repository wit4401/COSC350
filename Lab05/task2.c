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

//task 2.1
int openUtmpFile(){
    int fd;
    if((fd=open("/var/run/utmp",O_RDONLY))==-1){
        puts("Could not open file.");
        exit(1);
    }
    return fd;
}

int main(){
    setutent();
	int fd=openUtmpFile();
    printf("File descriptor for umpt.h: %d\n",fd);
    
    //task 2.2
    struct utmp *buf;
    int count=0;
    int i=0;
    buf=getutent();
    printf("Users: ");
    while(buf!=NULL){
        printf("%s ",buf->ut_user);
        if(buf->ut_type==USER_PROCESS)
            count++;
        buf=getutent();
    }
    puts("");
    printf("There are %d users logged in.\n",count);
    //closes the file and ends the 
    endutent();
    close(fd);
    exit(0);
}
