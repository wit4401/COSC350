#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char *argv[]){
    if(argc!=3){
        write(2,"Error! Please pass two arguements.\n",36);
        exit(2);
    }
    
    umask(000);
    int fileIn=open(argv[1],O_RDONLY);
    int fileOut=open(argv[2],O_CREAT | O_RDWR, 0666);
    if(fileIn==-1 || fileOut==-1){
        write(2,"Error! Cannot open file.\n",26);
        exit(1);  
    }
    
    char b;
    int rbyte;
    while((rbyte=read(fileIn,&b,1)>0)){
        int num = (int) b;
        write(fileOut,&num,rbyte);
    }
    puts("");
    exit(0);
}

