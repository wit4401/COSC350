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
	while((rbytes=read(PtoC[0],&b,1))>0){
		if(b!=' '){
			if(check){
				if(isdigit(b)){
					rNum2*=10;
					rNum2+=atoi(b);
				}
				else{
					puts("Error! 2nd input not an integer");
					_exit(2);
				}
			}
			else{
				if(isdigit(b)){
					rNum1*=10;
					rNum1+=atoi(b);
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
	_exit(0);
}

int main(){
	pid_t pid;
	int num1, num2;
	pipe(PtoC);
	pid=fork();
	//parent process
	if(pid>0){
		char *strNum1,*strNum2;
		close(PtoC[0]);
		printf("Enter a integer: ");
		scanf("%d",&num1);
		sprintf(strNum1,"%d",num1);

		printf("Enter a second integer: ");
		scanf("%d",&num2);
		sprintf(strNum2,"%d",num2);

		write(PtoC[1],strNum1,strlen(strNum1));
		write(PtoC[1]," ",1);
		write(PtoC[1],strNum2,strlen(strNum2));
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
		puts("Fork Error!");
		exit(1);
	}
}