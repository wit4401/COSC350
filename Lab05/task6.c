#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fileIn=open("foo",O_RDONLY);
    int fileOut=open("foorev2", O_CREAT | O_RDWR, 0760 );
    char buffer[1];
    int rbyte;
    off_t i=SEEK_END;

    while(i>=0){
        rbyte=pread(fileIn,buffer,rbyte,i--);
        write(fileOut,buffer,rbyte);
    }
    exit(0);
}
