#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[]){
	char buff;
	while((read(atoi(argv[1]),&buff,1))>0){
		write(1,&buff,1);
	}
}