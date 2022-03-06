/*
* Lab 3 Task 2
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
    int fileOut=open("clone1", O_CREAT | O_WRONLY,0666);//creates a file clone1 with rw-rw-rw permissions
    char b[1];//one byte buffer
    int rbyte;//number of bytes read
    
    //reads foo contents one byte at a time and writes them into clone1
    while((rbyte=read(fileIn,b,1)>0)){
        write(fileOut,b,rbyte);
    }

    //closes files opened    
    close(fileIn);
    close(fileOut);
    exit(0);
}
