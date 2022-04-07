#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
    int size=0;
    int file=open(argv[1],O_RDONLY);
    size=lseek(file,0,SEEK_END);
    printf("Size of %s: %d\n",argv[1],size);
    exit(0);
}
