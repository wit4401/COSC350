#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fileIn=open("foo",O_RDONLY);
    int fileOut=open("clone1", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    char b[1];
    int rbyte;
    
    while((rbyte=read(fileIn,b,1)>0)){
        write(fileOut,b,rbyte);
    }
    exit(0);
}
