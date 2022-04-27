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

void handler(int signo){
    signal(signo,SIG_DFL);//catches the signal and stops it from executing after unblocked
}

int main(){
    sigset_t set;//initializes a set of signals
    int i=1;//tracks the number in the loop

    sigaddset(&set,SIGINT);//adds SIGINT to set
    sigaddset(&set,SIGQUIT);//adds SIGQUIT to set
    sigprocmask(SIG_BLOCK,&set,NULL);//blocks both SIGINT and SIGQUIT

    signal(SIGQUIT,handler);//catches signal if sent in the first loop

    while(i<=5){
        printf("%d\n", i++);
        sleep(1);
    }
    
    puts("");

    kill(getpid(),SIGQUIT);//this send the SIGQUIT to current process in case never sent by user above

    sigemptyset(&set);//empties the set of signals 
    sigaddset(&set,SIGQUIT);//adds SIGQUIT to be unblocked 
    sigprocmask(SIG_UNBLOCK,&set,NULL);//unblocks the SIGQUIT (^\)

    i=1;//resets for the next loop
    while(i<=5){
        printf("%d\n", i++);
        sleep(1);
    }
    exit(0);
}
