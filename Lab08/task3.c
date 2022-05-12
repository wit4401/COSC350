/*********************
|    Lab 8 Task 3    |
|    Will Townsend   |
|      May 2022      |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

int PtoC[2];

void handler(int signo){
	char b;
	int rbytes;
	int rNum1=0;
	int rNum2=rNum1;
	int check=0;
	printf("Sum of integers: %d\n",rNum1+rNum2);
	_exit(0);
}

int main(int argc,char *argv[]){
	pid_t pid;
	pipe(PtoC);
	pid=fork();
	//parent process
	if(pid>0){
		close(PtoC[0]);
		write(PtoC[1],argv[1],strlen(argv[1]));
		write(PtoC[1]," ",1);
		write(PtoC[1],argv[2],strlen(argv[2]));
		kill(pid,SIGUSR1);
		wait(NULL);
		exit(0);
	}
	//child process
	else if(pid==0){
		close(PtoC[1]);
		signal(SIGUSR1,handler);
		pause();
	}
	//fork() error
	else{
		puts("fork() Error!");
		exit(1);
	}
}
