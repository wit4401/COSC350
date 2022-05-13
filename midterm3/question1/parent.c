#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>

int numLen(int num){
	int len=0;
	while(num!=0){
		num/=10;
		len++;
	}
	return len;
}

int main(){
	int num1,num2;
	char *str1,*str2;
	pid_t pid,pid2;

	scanf("%d",&num1);
	scanf("%d",&num2);
	
	str1=malloc(numLen(num1)*sizeof(char));
	str2=malloc(numLen(num2)*sizeof(char));
	sprintf(str1,"%d",num1);
	sprintf(str2,"%d",num2);

	pid=fork();
	if(pid==0)
		execl("/Users/williamtownsend/Desktop/SchoolWork/Spring2022/COSC350/midterm3/question1/child","./child","+",str1,str2,NULL);
	
	pid2=fork();
	if(pid2==0)
		execl("/Users/williamtownsend/Desktop/SchoolWork/Spring2022/COSC350/midterm3/question1/child","./child","-",str1,str2,NULL);
	else{
		waitpid(pid2,NULL,0);
		exit(0);
	}
}
