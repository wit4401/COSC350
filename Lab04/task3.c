#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int palind(int fd1, int fd2){
    off_t offset=lseek(fd1,0,SEEK_END);
    if((offset%2)==1)
        return 0;
    off_t mid=lseek(fd2,offset,SEEK_SET)/2;
    offset=lseek(fd1,0,SEEK_SET);
    
    char b;
    int index=0;
    char half1[mid];
    char half2[mid];
    
    while(offset<=mid){
        read(fd1,&b,1);
        half1[index++]=b;
        offset++;
    }
    
    index=0;
    offset=lseek(fd1,0,SEEK_END)-1;
    while(offset>=mid){
        read(fd1,&b,1);
        half2[index++]=b;
        lseek(fd1,offset--,SEEK_SET);
    }
    
    for(int i=0;i<index*2;i++){
        if(half1[i]!=half2[i])
            return 0;
    }
    return 1;
}   

int main(){
    int file=open("task3.txt",O_RDONLY);
    
    int res=palind(file,dup(file));
    if(res==0)
        puts("The file content is not a palindrome!");
    else
        puts("The file content is a palindrome!");
    exit(0);
}
