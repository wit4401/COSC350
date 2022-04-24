/*********************
|    Lab 7 Task 2    |
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
#include<sys/wait.h>

int main(){
    pid_t pid=fork();
    umask(0000);//allows  all  permissions 
    int fd=open("foo",O_CREAT | O_TRUNC | O_RDWR,0755);//creates a file named foo
    switch(pid){
        case -1: //case  of fork error 
            puts("fork error!");
            exit(1);
        case 0: //child process
            write(fd,"Hi, Mom\n",9);
            _exit(0);
        default://parent process 
            wait(NULL);
            int rbyte;
            char  b;
            write(1,"My son said ",12);
            while((rbyte=read(fd,&b,1))>0)
                write(1,&b,rbyte);
            exit(0);
    }
}
