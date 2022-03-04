#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fileIn1=open("foo",O_RDONLY);
    int fileIn2=open("foo1",O_RDONLY);
    int fileOut=open("foo12", O_CREAT | O_RDWR,0760);
    char buffer[1024];
    int rbyte;

    while((rbyte=read(fileIn1,buffer,1024))>0){
        write(fileOut,buffer,rbyte);    
    }
    
    lseek(fileOut,-1,SEEK_END);
    
    while((rbyte=read(fileIn2,buffer,1024))>0){
        write(fileOut,buffer,rbyte);
    }
    
    exit(0);
}

