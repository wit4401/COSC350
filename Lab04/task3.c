/*********************
|    Lab 4 Task 3    |
|    Will Townsend   |
|    March  2022     |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int palind(int fd1, int fd2){
    char b1;//single byte buffer
    char b2;//another single byte buffer
    off_t offsetFD2=lseek(fd2,0,SEEK_END)-1;//sets the cursor of the file to the last character
    off_t offsetFD1=0;
    if((offsetFD2+1)%2==1){
        while(offsetFD1!=offsetFD2){
            lseek(fd1,offsetFD1++,SEEK_SET);
            read(fd1,&b1,1);
            lseek(fd2,--offsetFD2,SEEK_SET);
            read(fd2,&b2,1);
            if(b1!=b2)
                return 0;
        }
    }
    else{
        while(offsetFD1!=offsetFD2-1){
            lseek(fd1,offsetFD1++,SEEK_SET);
            read(fd1,&b1,1);
            lseek(fd2,--offsetFD2,SEEK_SET);
            read(fd2,&b2,1);
            if(b1!=b2)
                return 0;
        }
    }
    return 1;//it has looped through successfully and is indeed a palindrome
}   

int main(){
    int file=open("task3.txt",O_RDONLY);//opens a test file called task3.txt
    int sameFile=dup(file);//another file descriptor for our opened file
    int res=palind(file,sameFile);//initialized and grabs the result of palind()
    
    //displays whether the content is a palindrome or not
    if(res==0)
        puts("The file content is not a palindrome!");
    else
        puts("The file content is a palindrome!");
    exit(0);
}
