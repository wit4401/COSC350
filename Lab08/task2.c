/*********************
|    Lab 8 Task 2    |
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

int scores[20]; //global array of scores
int numOfScores=0;

//action of the first thread (grabs user input for the score)
void *getScores(void *arg){
	int score=0;
	while(numOfScores!=20&&score>=0){
		printf("Enter a score #%d(max of 20 and -1 to stop): ",numOfScores);
		scanf("%d",&score);
		if(score>=0)
			scores[numOfScores++]=score;
	}
}

//action of the second thread (finds the average and meadian score) works simultaneously with thread 3
void *avgMedianScore(void *arg){
	int avg=0;
	for(int i=0;i<numOfScores;i++)
		avg+=scores[i];
	printf("Avgerage: %d\n",avg/numOfScores);
	printf("Median: %d\n",scores[(numOfScores/2)-1]);
}

//action of the third thread (finds min and max score) works simultaneously with thread 2
void *minMaxScores(void *arg){
	int min=9999999;
	int max=-9999999;
	for(int i=0;i<numOfScores;i++){
		if(min>scores[i])
			min=scores[i];
		if(max<scores[i])
			max=scores[i];
	}
	printf("Maximum: %d\n",max);
	printf("Minimum: %d\n",min);
}

//action of the fourth thread (clears the array)
void *clearBuffer(void *arg){
	for(int i=0;i<numOfScores;i++)
		scores[i]=0;
	printf("Scores Cleared!\n");
}

int main(){
	pthread_t thread1,thread2,thread3,thread4;
	pthread_create(&thread1,NULL,getScores,NULL);//creates thread 1
	pthread_join(thread1,NULL);//waits for thread 1 to exit
	pthread_create(&thread2,NULL,avgMedianScore,NULL);//creates thread 2
	pthread_create(&thread3,NULL,minMaxScores,NULL);//create thread 3
	pthread_join(thread2,NULL);//waits for thread 2 to exit
	pthread_join(thread3,NULL);//waits for thread 3 to exit
	pthread_create(&thread4,NULL,clearBuffer,NULL); //creates thread 4
	
	pthread_exit(NULL);
}