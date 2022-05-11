#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main(int argc,char *argv[]){
	if(argv[1][0]=='-'){
		int num1=atoi(argv[2]);
		int num2=atoi(argv[3]);
		printf("%d\n",num1-num2);
	}
	else if(argv[1][0]=='+'){
		int num1=atoi(argv[2]);
		int num2=atoi(argv[3]);
		printf("%d\n",num1+num2);
	}
	else
		puts("Error!");
	_exit(0);
}