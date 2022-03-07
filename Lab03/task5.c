/*
* Lab 3 Task 5
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
    int fileOut=open("foorev", O_CREAT | O_RDWR, 0760 );//creates a file foorev with rwxrw---- permissions
    char buffer[1];//one byte buffer
    int rbyte;//number of bytes read
    off_t offset=lseek(fileIn,0,SEEK_END)-1;//initial offset (cursor set to the end of the file)
    
    //reads through foo backwards
    while((rbyte=read(fileIn,buffer,1))>0){
        write(fileOut,buffer,rbyte);//write the current byte
        lseek(fileIn,offset--, SEEK_SET);//moves the cursor back a position
    }
    
    //closes files opened    
    close(fileIn);
    close(fileOut);
    exit(0);
}

