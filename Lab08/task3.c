#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>

int main(){
	int PtoC[2];
	pid_t pid=fork();
	pipe(PtoC);
	switch (pid){
		case -1:

		case 0:
			waitpid(getppid(),);
			_exit()
		default:
			exit();
	}
}
