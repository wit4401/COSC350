/*********************
|    Lab 6 Task 4    |
|      (child)       |
|    Will Townsend   |
|    April  2022     |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc,char *argv[]){
    for(int i=1;i<=atoi(argv[0]);i++){
        printf("This is the child. pid=%d\n",getpid());
        sleep(atoi(argv[1]));
    }
    exit(0);
}
