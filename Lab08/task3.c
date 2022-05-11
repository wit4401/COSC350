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
	while(rbytes=read(PtoC[0],&b,1)){
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

int numLen(int val){
	int len=0;
	while(val!=0){
		len++;
		val/=10;
	}
	return len;
}

int main(){
	pid_t pid;
	int num1, num2;
	pipe(PtoC);
	pid=fork();
	//parent process
	if(pid>0){
		close(PtoC[0]);
		printf("Enter a integer: ");
		scanf("%d",&num1);
		char *str1=malloc(numLen(num1)*sizeof(char));;
		sprintf(str1,"%d",num1);

		printf("Enter a second integer: ");
		scanf("%d",&num2);
		char *str2=malloc(numLen(num2)*sizeof(char));
		sprintf(str2,"%d",num2);

		write(PtoC[1],str1,strlen(str1));
		write(PtoC[1]," ",1);
		write(PtoC[1],str2,strlen(str2));
		kill(pid,SIGUSR1);

		free(str1);
		free(str2);
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
