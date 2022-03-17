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
    //error checks arguement values.
    if(argc!=3){
        puts("Must pass two arguements!");
        exit(1);
    }
    struct stat fileType;//makes the stat struct to get file info
    char oldPath[1024];//contains the oldPath of the file
    char newPath[1024];//contians the newPath for the file
    char *pwd="/mnt/linuxlab/home/wtownsend2/COSC350/Lab04/";//character pointer holds the pwd
    
    //attaches the argv[2] to the newPath and pwd to oldPath
    strcpy(oldPath,pwd);
    strcpy(newPath,argv[2]);
    
    //checks for the file
    int fd;
    if((fd=open(argv[1],O_RDONLY))==-1){
        puts("File doesn't exist.");
        exit(2);
    }
    close(fd);
    
    /*
    * Checks if the file exists/is a directory, if it is then it will link the file to its new destination 
    * and unlink the old destination. If no file exists it needs to rename the file to the appropriate
    * name indicated. If a file exists it asks the user if they want to overwrite the file and does so
    * accordingly.
    */
    if (stat(newPath,&fileType)==-1){
        int len=strlen(newPath)-1;
        int newNameLen=0;
        char newOld[1024];
        
        //finds the length of the new name
        while(newPath[len--]!='/')
            newNameLen++;
        
        char rev[newNameLen];
        char newName[newNameLen];
        int index=newNameLen;
        len=strlen(newPath);
        int lenI=len-1;
        
        //this copies the contents of last elements newPath (i.e. the new name of the file)
        for(int i=0;i<newNameLen;i++)
            rev[i]=newPath[lenI--];
        
        for(int i=0;i<newNameLen;i++)
            newName[i]=rev[--index];
         
        strcat(newOld,oldPath);
        strcat(oldPath,argv[1]);
        strcat(newOld,newName);
        
        //renames the file and links 
        rename(oldPath,newOld);
        link(newOld,newPath);
        unlink(newOld);
    }
    else{
        if(S_ISDIR(fileType.st_mode)){
            //finalizes the paths
            strcat(oldPath,argv[1]);
            strcat(newPath,"/");
            strcat(newPath,argv[1]);
            //links the new path and unliks the old one
            if (link(oldPath,newPath)==-1){printf("Error\n");}
            if (unlink(oldPath)==-1){printf("Error\n");}
        }
        //this does the same as above (as if no file existed) but confirms if the file is to be overwritten or not
        else if(S_ISREG(fileType.st_mode)){
            char confir='m';
            while(confir!='n' && confir!='y'){         
                puts("\nA file with that name exists.");
                printf("Overwrite File? (y/n): ");
                scanf(" %c",&confir);
                if(confir!='n' && confir!='y')
                    puts("Invalid Input!");
                if(confir=='n')
                    exit(3);
            }
            puts("");            
            unlink(newPath);
            int len=strlen(newPath)-1;
            int newNameLen=0;
            char newOld[1024];
        
            while(newPath[len--]!='/')
                newNameLen++;
        
            char rev[newNameLen];
            char newName[newNameLen];
            int index=newNameLen;
            len=strlen(newPath);
            int lenI=len-1;
        
            for(int i=0;i<newNameLen;i++)
                rev[i]=newPath[lenI--];
        
            for(int i=0;i<newNameLen;i++)
                newName[i]=rev[--index];
        
            strcat(newOld,oldPath);
            strcat(oldPath,argv[1]);
            strcat(newOld,newName);
        
            //renames the file and links 
            rename(oldPath,newOld);
            link(newOld,newPath);
            unlink(newOld);
        }
        else{
            puts("Unknown Error");
            exit(4);
        }
    }
    exit(0);
}
