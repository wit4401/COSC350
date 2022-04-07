#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int rbyte;
    char b;
    umask(0000);
    int fileIn=open("input",O_RDONLY);
    int fileOut=open("output",O_CREAT | O_RDWR,0755);
    off_t offset=lseek(fileIn,0,SEEK_END)-1;
    
    while(offset>=0){
        rbyte=read(fileIn,&b,1);
        if(isdigit(b))
            write(fileOut,&b,rbyte);
        lseek(fileIn,offset--,SEEK_SET);
    }
    rbyte=1;
    while(rbyte>0){
        rbyte=read(fileIn,&b,1);
        if(!isdigit(b))
            write(fileOut,&b,rbyte);
    }
    close(fileIn);
    close(fileOut);
    exit(0);
}
