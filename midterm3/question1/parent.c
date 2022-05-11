#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main(){
	int num1,num2;
	scanf("%d",&num1);
	scanf("%d",&num2);
	pid_t pid=fork();
	char *str1,*str2;
	switch (pid){
		case -1:
			puts("fork() error");
			exit(1);
		case 0:
			sprintf(str1,"%d",num1);
			sprintf(str2,"%d",num2);
			execl("/Users/williamtownsend/Desktop/midterm3/question1/child","./child","+",str1,str2,NULL);
			break;
		default:
			break;
	}
	pid_t pid2=fork();
	char *str3,*str4;
	switch (pid2){
		case -1:
			puts("fork() error");
			exit(1);
		case 0:
			sprintf(str3,"%d",num1);
			sprintf(str4,"%d",num2);
			execlp("/Users/williamtownsend/Desktop/midterm3/question1/child","./child","-",str3,str4,NULL);
			break;
		default:
			waitpid(pid2,NULL,0);
			exit(0);
	}

}