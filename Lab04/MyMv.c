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
    char oldPath[1024];
    char newPath[1024];
    char *pwd="/home/wit4401/Desktop/COSC350/Lab04/";
    
    strcat(oldPath,pwd);
    strcpy(newPath,argv[2]);

    if (stat(newPath,&fileType)==-1){
        int len=strlen(newPath)-1;
        int newNameLen;
        char newOld[1024];
        
        while(newPath[len--]!='/')
            newNameLen++;
        
        char rev[newNameLen];
        char newName[newNameLen];
        int index=newNameLen;
        len=strlen(newPath);
        int lenI=len-1;
        
        for(int i=0;i<len;i++)
            rev[i]=newPath[lenI--];
        
        len=index;
        for(int i=0;i<len;i++)
            newName[i]=rev[--index];
        
        strcat(newOld,oldPath);
        strcat(oldPath,argv[1]);
        strcat(newOld,newName);
        
        rename(oldPath,newOld);
        link(oldPath,newPath);
        unlink(oldPath);
    }
    else{
        if(S_ISDIR(fileType.st_mode)){
            strcat(oldPath,argv[1]);
            strcat(newPath,"/");
            strcat(newPath,argv[1]);
            if (link(oldPath,newPath)==-1){printf("Error\n");}
            if (unlink(oldPath)==-1){printf("Error\n");}
        }
        else if(S_ISREG(fileType.st_mode)){
            puts("File name exists!");
            exit(1);
        }
        else{
            puts("Unknown Error");
            exit(2);
        }
    }
    exit(0);
}
