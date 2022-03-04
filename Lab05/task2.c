#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    umask(000);
    int fileIn=open("foo",O_RDONLY);
    int fileOut=open("clone1", O_CREAT | O_WRONLY,0666);
    char b[1];
    int rbyte;
    
    while((rbyte=read(fileIn,b,1)>0)){
        write(fileOut,b,rbyte);
    }
    exit(0);
}
