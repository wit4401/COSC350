#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    char buffer[128];
    int bytes;
    while ((bytes=read(0,buffer,128))>0){
        write(1,buffer,bytes);
    }
    exit(0);
}
