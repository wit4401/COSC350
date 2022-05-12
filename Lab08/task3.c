/*********************
|    Lab 8 Task 3    |
|    Will Townsend   |
|      May 2022      |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int PtoC[2];

int main(int argc,char *argv[]){
	pid_t pid;
	pipe(PtoC);//creates the pipe
	pid=fork();
	//parent process
	if(pid>0){
		close(PtoC[0]);//closes the ability for the parent to read the contents of pipe

		//writes the argument values into the pipe
		write(PtoC[1],argv[1],strlen(argv[1]));
		write(PtoC[1]," ",1);
		write(PtoC[1],argv[2],strlen(argv[2]));
		exit(0);
	}
	//child process
	else if(pid==0){
		int num1,num2,rbytes,error;
		char str[1024];
		close(PtoC[1]);//closes the ability for the child to write into the pipe
		read(PtoC[0],str,80);//reads the entire string from the pipe
		error=sscanf(str,"%d%d",&num1,&num2);//grabs the two integers from the string
		if(error!=2){
			puts("Error! One value is not an integer!");
			exit(2);
		}
		printf("%d+%d=%d\n",num1,num2,num1+num2);
		_exit(0);
	}
	//fork() error
	else{
		puts("fork() Error!");
		exit(1);
	}
}
