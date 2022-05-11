#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>

int numLen(int val){
	int len=0;
	while(val!=0){
		len++;
		val/=10;
	}
	return len;
}

int main(){
	int num1,num2;
	scanf("%d",&num1);
	scanf("%d",&num2);
	pid_t pid;
	pid=fork();
	char *str1=malloc(numLen(num1)*sizeof(char));
	char *str2=malloc(numLen(num2)*sizeof(char));
	if(pid==-1){
		puts("fork() error");
		exit(1);
	}
	else if(pid==0){
		sprintf(str1,"%d",num1);
		sprintf(str2,"%d",num2);
		execl("/mnt/linuxlab/home/wtownsend2/COSC350/midterm3/question1/child","./child","+",str1,str2,NULL);
	}

	pid_t pid2=fork();
	char *str3=malloc(numLen(num1)*sizeof(char));
	char *str4=malloc(numLen(num2)*sizeof(char));
	if(pid2==-1){
		puts("fork() error");
		exit(1);
	}
	else if(pid2==0){
		sprintf(str3,"%d",num1);
		sprintf(str4,"%d",num2);
		execl("/mnt/linuxlab/home/wtownsend2/COSC350/midterm3/question1/child","./child","-",str3,str4,NULL);
	}
	else{
		waitpid(pid2,NULL,0);
		exit(0);
	}
}