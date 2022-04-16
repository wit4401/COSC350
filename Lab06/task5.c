/*********************
|    Lab 6 Task 5    |
|    Will Townsend   |
|    April  2022     |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc,char *argv[]){
	if(argc!=2){
		puts("Must pass one arguement!");
		exit(1);
	}
	int input=open(argv[1],O_RDONLY);
	if(input<0){
		puts("Cannot Open File");
		exit(2);
	}
	pid_t pid=fork();
	
	if(pid==0){
		int rbytes;
		char b;
		int childOut=open("childOut",O_CREAT | O_RDWR, 0755);
	}
	else if(pid>0){
		int rbytes;
		char b;
		int parentOut=open("parentOut",O_CREAT | O_RDWR, 0755);
	}
	else{
		puts("fork error");
		exit(0);
	}
}