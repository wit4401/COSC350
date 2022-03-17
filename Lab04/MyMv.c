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
    struct stat fileType;//stores file data
    char oldPath[1024]; //character array for the path of selected file
    char newPath[1024]; //character array for the newPath of the selected file
    char *pwd="/mnt/linuxlab/home/wtownsend2/COSC350/Lab04/"; //the pwd of the file
    strcpy(oldPath,pwd); //
    strcpy(newPath,argv[2]);//copies the newPath to the
 
    //check to see if the file exists
    if(open(argv[1],O_RDONLY)==-1){ 
        puts("File doesn't exist."); 
        exit(2); 
    }
    //all these statements check the newPath to see if it is a directory, a nonexistent file, or an existing file and executes
    //proceedors accordingly
    if (stat(newPath,&fileType)==-1){ 
        //if the file doesnt exist it simply renames the file and moves it to the correct location
        strcat(oldPath,argv[1]);
        rename(oldPath,newPath); 
    } 
    else{
        //if it is a directory it moves the file into the selected directory
        if(S_ISDIR(fileType.st_mode)){ 
            strcat(oldPath,argv[1]); 
            strcat(newPath,"/"); 
            strcat(newPath,argv[1]);
            if (link(oldPath,newPath)==-1){printf("Error\n");} 
            if (unlink(oldPath)==-1){printf("Error\n");} 
        } 
        //if the file exists it asks the user if they want to overwrite and does the same as if the file didn't exist
        //rename and moves.
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
            strcat(oldPath,argv[1]);
            rename(oldPath,newPath); 
        }
        else{ 
            puts("Unknown Error"); 
            exit(4); 
        } 
    } 
    exit(0); 
} 
