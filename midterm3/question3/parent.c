#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/stat.h>

pid_t pid;
int parentPipe[2];
char fd[10];

void handler(int signo){
	write(parentPipe[1],"I am here, baby\n",16);
	kill(pid,SIGUSR1);
}

void handler2(int signo){
	execl("/Users/williamtownsend/Desktop/SchoolWork/Spring2022/COSC350/midterm3/question3/child", "./child",fd,NULL);
}

int main(){
	pipe(parentPipe);
	pid=fork();
	switch(pid){
		case -1:
			puts("fork() error");
			exit(1);
		case 0:
			close(parentPipe[1]);
			signal(SIGUSR1,handler2);
			sprintf(fd,"%d",parentPipe[0]);
			while(1)
				pause();
		default:
			close(parentPipe[0]);
			signal(SIGALRM,handler);
			while(1){
				alarm(10);
				pause();
			}
	}
}
