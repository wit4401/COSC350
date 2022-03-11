/*********************
|    Lab 4 Task 5    |
|    Will Townsend   |
|    March  2022     |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char *argv[]){
    struct stat fileType;
    if (stat(argv[2],fileType)==-1){
        puts("lstat Error");
        exit(1);
    }
    if(S_ISDIR(fileType.st_mode)){
        
    }
    else if(S_ISREG(fileType.st_mode)){
        
    }
    else{
        puts("Unknown Error");
        exit(2);
    }
    exit(0);
}
