#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[]){
	char buff[16];
	read(atoi(argv[1]),buff,16);
	write(1,buff,16);
}