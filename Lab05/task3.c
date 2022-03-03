#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fileIn=open("foo",O_RDONLY);
    int fileOut=open("clone2", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP);
    char buffer[32];
    int rbyte;
    
    while((rbyte=read(fileIn,buffer,32))>0){
        write(fileOut,buffer,rbyte);
    }
    exit(0);
}
