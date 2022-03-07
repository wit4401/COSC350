/*
* Lab 3 Task 6
* COSC 350
* Will Townsend
*/
#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    umask(000);//allows all permissions to be activated for usr, grp, or oth
    int fileIn=open("foo",O_RDONLY);//opens a file called foo w/read only permission
    int fileOut=open("foorev2", O_CREAT | O_RDWR, 0760 );//creates a file foorev2 with rwxrw---- permissions
    char buffer[1];//one byte buffer
    int rbyte;//number of bytes read
    off_t i=0;//initializes the file size
    
    //determines the size of the file (to set the offset correctly)
    while((read(fileIn,buffer,1))>0)
        i++;
    
    //does the same as task 5 but uses pread to combine the lseek and read functions
    while((rbyte=pread(fileIn,buffer,1,--i))>0)
        write(fileOut,buffer,rbyte);
    
    //close files opened
    close(fileIn);
    close(fileOut);
    exit(0);
}
