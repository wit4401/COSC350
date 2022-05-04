#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<ctype.h>
#include<sys/stat.h>
#include<sys/types.h>
#include"huffman.h"

int main(int argc,char *argv[]){
	//checks that an arguement has been passed
    if(argc!=2){
        printf("Error!\n");
        exit(1);
    }
    
    //opens the file and opens it (if not sends an error message and exits program)
    umask(0000);
    int original=open("original.txt",O_CREAT | O_TRUNC | O_WRONLY,0755);
    FILE *file=fopen(argv[1],"r");
    if (file==NULL){
        printf("Open Error!\n");
	    exit(2);
    }
    if(original<0){
    	printf("Open Error!\n");
	    exit(3);
    }
    
}
