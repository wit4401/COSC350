#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main(int argc,char *argv[]){
	int num1,num2;
	if(argv[1][0]=='-'){
		num1=atoi(argv[2]);
		num2=atoi(argv[3]);
		printf("%d - %d = %d\n",num1,num2,num1-num2);
	}
	else if(argv[1][0]=='+'){
		num1=atoi(argv[2]);
		num2=atoi(argv[3]);
		printf("%d + %d = %d\n",num1,num2,num1+num2);
	}
	else{
		puts("Error!");
		_exit(1);
	}
	_exit(0);
}