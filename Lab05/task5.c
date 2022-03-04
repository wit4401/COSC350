#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    umask(000);
    int fileIn=open("foo",O_RDONLY);
    int fileOut=open("foorev", O_CREAT | O_RDWR, 0760 );
    char buffer[1];
    int rbyte;
    int offset=lseek(fileIn,0,SEEK_END)-1;

    while(offset>=-1){
        rbyte=read(fileIn,buffer,1);
        write(fileOut,buffer,rbyte);
        lseek(fileIn,offset--, SEEK_SET);
    }

    exit(0);
}

