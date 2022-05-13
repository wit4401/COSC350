#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc,char *argv[]){
	pid_t pid;
	pid=fork();
	if(pid==-1){
		puts("fork() error");
		exit(1);
	}
	else if(pid==0)
		execl("/mnt/linuxlab/home/wtownsend2/COSC350/midterm3/question1/child","./child","+",argv[1],argv[2],NULL);

	pid_t pid2=fork();
	if(pid2==-1){
		puts("fork() error");
		exit(1);
	}
	else if(pid2==0)
		execl("/mnt/linuxlab/home/wtownsend2/COSC350/midterm3/question1/child","./child","-",argv[1],argv[2],NULL);
	else{
		waitpid(pid2,NULL,0);
		exit(0);
	}
}
