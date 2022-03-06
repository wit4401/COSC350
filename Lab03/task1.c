/*
* Lab 3 Task 1
* COSC 350
* Will Townsend
*/
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    char buffer[128];//128 byte buffer
    int bytes;//number of bytes read

    //loops through the standard (user) input 128 bytes at a time
    while ((bytes=read(0,buffer,128))>0){
        write(1,buffer,bytes); //writes the bytes to the standard output 
    }
    exit(0);
}
