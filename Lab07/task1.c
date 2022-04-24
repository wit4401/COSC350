/*********************
|    Lab 7 Task 1    |
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

void sig_handler(int signo){
    //once the alarm signal is recieved it yells at the user until ^C is hit
    if(signo==SIGALRM){
        while(1){
            puts("Ring Ring");
            sleep(1);
            signal(SIGINT,sig_handler);//constantly waits to catch the interruption signal
        }
    }
    //once ^C is pressed it confirms the termination and signal that is sent
    else if(signo==SIGINT){
        puts("\nAlarm Terminated");
        exit(0);
    }
}
int main(){
    alarm(5);//sends the alarm signal after 5 seconds
    signal(SIGALRM,sig_handler);//catches the actual alarm signal
    pause();//patiently waits for a signal to be caught
}
