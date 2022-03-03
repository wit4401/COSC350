#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fileIn=open("foo",O_RDONLY);
    int fileOut=open("foorev2", O_CREAT | O_RDWR, 0660 );
    char buffer[1];
    int rbyte;
    int i=1;
    while((rbyte=pread(fileIn,buffer,rbyte,SEEK_END-i))>0){
        write(fileOut,buffer,rbyte);
        i++;
    }
    exit(0);
}
