/*
* Lab 3 Task 3
* COSC 350
* Will Townsend
*/
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){

    umask(000);//allows all permissions to be activated for usr, grp, or oth
    int fileIn=open("foo",O_RDONLY);//opens a file called foo w/read only permission
    int fileOut=open("clone2", O_CREAT | O_WRONLY,0770);//creates a file clone2 with rwxrwx--- permissions
    char buffer[32];//32 byte buffer
    int rbyte;//number of bytes read
    
    //reads foo contents 32 bytes at a time and writes them into clone2
    while((rbyte=read(fileIn,buffer,32))>0){
        write(fileOut,buffer,rbyte);
    }
    
    //closes files opened    
    close(fileIn);
    close(fileOut);
    exit(0);
}
