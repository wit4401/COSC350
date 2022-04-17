/*********************
|    Lab 6 Task 5    |
|    Will Townsend   |
|    April  2022     |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int myIsDigit(char b){
	if(b>='0'&&b<='9')
		return 1;
	else
		return 0;
}

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
		int childOut=open("child.txt",O_CREAT | O_RDWR, 0755);
		while((rbytes=read(input,&b,1))>0){
			if(!myIsDigit(b))
				write(childOut,&b,rbytes);
		}
		_exit(0);
	}
	else if(pid>0){
		int rbytes;
		char b;
		int parentOut=open("parent.txt",O_CREAT | O_RDWR, 0755);
		while((rbytes=read(input,&b,1))>0){
			if(myIsDigit(b))
				write(parentOut,&b,rbytes);
		}
		exit(0);
	}
	else{
		puts("fork error");
		exit(0);
	}
}