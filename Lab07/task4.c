/*********************
|    Lab 7 Task 4    |
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
#include<sys/signal.h>

int main(){

    sigset_t set;
    int i=1;

    sigaddset(&set,SIGINT);
    sigaddset(&set,SIGQUIT);
    sigprocmask(SIG_BLOCK,&set1,NULL);

    while(i<=5){
        printf("%d\n", i++);
        sleep(1);
    }

    puts("");

    sigemptyset(&set);
    sigaddset(&set,SIGINT);
    sigprocmask(SIG_BLOCK,&set2,NULL);

    i=1;
    while(i<=5){
        printf("%d\n", i++);
        sleep(1);
    }
    exit(0);
}
