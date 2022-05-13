#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<pthread.h>

int result=0;

void *func1(void *val){
	result=atoi((char *)val)*10;
	return val;
}

void *func2(void *val){
	result+=20;
	return val;
}

void *func3(void *val){
	result/=4;
	return val;
}

int main(int argc,char *argv[]){
	pthread_t thread1,thread2,thread3;
	int num=atoi(argv[1]);

	printf("Starting Value: %d\n",atoi(argv[1]));

	pthread_create(&thread1,NULL,func1,(void *) argv[1]);
	pthread_join(thread1,NULL);

	pthread_create(&thread2,NULL,func2,NULL);
	pthread_join(thread2,NULL);

	pthread_create(&thread3,NULL,func3,NULL);
	pthread_join(thread3,NULL);
	
	printf("Ending Value: %d\n",result);
	pthread_exit(NULL);
}
