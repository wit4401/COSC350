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
    for(int i=1;i<=atoi(argv[1]);i++){
        printf("%s. pid=%d\n",argv[0],getpid());
        sleep(atoi(argv[2]));
    }
    _exit(37);
}
