#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fileIn=open("foo",O_RDONLY);
    int fileOut=open("clone2", O_CREAT | O_WRONLY,0770);
    char buffer[32];
    int rbyte;
    
    while((rbyte=read(fileIn,buffer,32))>0){
        write(fileOut,buffer,rbyte);
    }
    exit(0);
}
