/*********************
|    Lab 8 Task 1    |
|    Will Townsend   |
|      May 2022      |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h> 

int num=0;
void *calcSum(void *val){
	int sum=0;
	for(int i=1;i<=num;i++)
		sum+=i;
	printf("Summation: %d\n",sum);
}

void *calcFact(void *val){
	int fact=1;
	for(int i=1;i<=num;i++)
		fact*=i;
	printf("%d!=%d\n",num,fact);
}

int main(){
	pthread_t thread1,thread2;
	void *ex1,*ex2;

	printf("Enter a positive number: ");
	scanf("%d",&num);
	pthread_create(&thread1,NULL,calcSum,NULL);
	pthread_create(&thread2,NULL,calcFact,NULL);
	pthread_exit(NULL);
}