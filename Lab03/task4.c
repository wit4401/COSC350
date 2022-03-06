/*
* Lab 3 Task 4
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
    int fileIn1=open("foo",O_RDONLY);//opens a file called foo w/read only permission
    int fileIn2=open("foo1",O_RDONLY);//opens a file called foo1 w/read only permission
    int fileOut=open("foo12", O_CREAT | O_RDWR,0760);//creates a file foo12 with rwxrw---- permissions
    char buffer[1024];//1024 byte buffer
    int rbyte;//number of bytes read
    
    //reads foo contents 1024 bytes at a time and writes them into foo12
    while((rbyte=read(fileIn1,buffer,1024))>0){
        write(fileOut,buffer,rbyte);    
    }
    
    lseek(fileOut,0,SEEK_END);//sets the cursor/offset the end of foo12
    
    //reads foo1 contents 1024 bytes at a time and writes them into foo12
    while((rbyte=read(fileIn2,buffer,1024))>0){
        write(fileOut,buffer,rbyte);
    }
    
    //closes files opened    
    close(fileIn1);
    close(fileIn2);
    close(fileOut);
    exit(0);
}

