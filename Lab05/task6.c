#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    umask(000);
    int fileIn=open("foo",O_RDONLY);
    int fileOut=open("foorev2", O_CREAT | O_RDWR, 0760 );
    char buffer[1];
    int rbyte;
    int i=0;
    
    while((read(fileIn,buffer,1))>0)
        i++;
    
    while((rbyte=pread(fileIn,buffer,1,--i))>0)
        write(fileOut,buffer,rbyte);
    exit(0);
    
    close(fileIn);
    close(fileOut);
}
