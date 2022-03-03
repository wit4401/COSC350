#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    char buffer[128];
    int bytes;
    while (bytes=read(1,buffer,128)>0){
        write(0,buffer,128);
    }
    exit(0);
}
