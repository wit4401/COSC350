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
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>

int PtoC[2];

void handler(int signo){
	char b;
	int rbytes;
	int rNum1=0;
	int rNum2=rNum1;
	int check=0;
	while((rbytes=read(PtoC[0],&b,1))){
		if(b!=' '){
			if(check){
				if(isdigit(b)){
					rNum2*=10;
					rNum2+=atoi(&b);
				}
				else{
					puts("Error! 2nd input not an integer");
					_exit(2);
				}
			}
			else{
				if(isdigit(b)){
					rNum1*=10;
					rNum1+=atoi(&b);
				}
				else{
					puts("Error! 1st input not an integer");
					_exit(1);
				}
			}
		}
		else
			check=1;
	}
	printf("Sum of inputs: %d\n",rNum1+rNum2);
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
		exit(0);
	}
	//child process
	else if(pid==0){
		close(PtoC[1]);
		signal(SIGUSR1,handler);
		pause();
		_exit(0);
	}
	//fork() error
	else{
		puts("Fork Error!");
		exit(1);
	}
}
