/*********************
|    Lab 4 Task 5    |
|    Will Townsend   |
|    March  2022     |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char *argv[]){
    if(argc!=3){
        puts("Must pass two arguements!");
        exit(1);
    }
    
    struct stat fileType;
    char *pwd="/mnt/linuxlab/home";
    char *pathTo=argv[2];
    char oldPath=argv[1];
    if (pathTo[0]=='~'){
        for(int i=0;i<strlen(pathTo)-1;i++)
            pathTo[i]=pathTo[i+1];
        strcat(pwd,pathTo);
    }
    strcat("/COSC350/",oldPath);
    strcat(pwd,oldPath);
    printf("Old Path: %s\n",oldPath);
    printf("New Path: %s\n",pathTo)
    if (stat(pathTo,&fileType)==-1){
        puts("lstat Error");
        exit(2);
    }
    if(S_ISDIR(fileType.st_mode)){
        char *newPath;
        strcpy(argv[1],newPath);
        strcat('/',newPath);
        srtcat(path,newPath);
        link(newPath,oldPath);
        unlink(oldPath);
    }
    else if(S_ISREG(fileType.st_mode)){
        link(oldPath,newPath);
        unlink(oldPath);
    }
    else{
        puts("Unknown Error");
        exit(2);
    }
    exit(0);
}
