#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/stat.h>

int PtoC[2];
int CtoP[2];
pid_t pid;

void handler(int signo){
    if(signo==SIGUSR1){
        char buff[7];
        read(CtoP[0],buff,7);
        write(1,"My child said, ",15);
        write(1,buff,8);
        puts("");
        write(PtoC[1],"I love you",10);
        kill(pid,SIGUSR2);
        wait(NULL);
        exit(0);
    }
    else if(signo==SIGUSR2){
        char buff[10];
        read(PtoC[0],buff,10);
        write(1,"My mom said, ",13);
        write(1,buff,10);
        puts("");
        _exit(0);
    }
}

int main(){
    pipe(PtoC);
    pipe(CtoP);
    pid=fork();
    if(pid>0){
        close(PtoC[0]);
        close(CtoP[1]);
        signal(SIGUSR1,handler);
        pause();
    }
    else{
        close(PtoC[1]);
        close(CtoP[0]);
        write(CtoP[1],"Hi, mom",7);
        kill(getppid(),SIGUSR1);
        signal(SIGUSR2,handler);
        pause();
    } 
}