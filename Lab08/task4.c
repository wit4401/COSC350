/*********************
|    Lab 8 Task 4    |
|    Will Townsend   |
|      May 2022      |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char** argv){
    int size=0;
    char* shellCommand;//will store the shell command
    
    //finds the size of our command
    for(int i=1; i<argc; i++){
        size+=strlen(argv[i]);
    }

    shellCommand=malloc(size*sizeof(char));//allocates memory to store the shell command

    //concatenates each arguement value to create the entire shell command
    for(int i=1; i<argc; i++)
        sprintf(shellCommand, "%s %s", shellCommand, argv[i]);

    char buffer[BUFSIZ];
    FILE* ptr;
    //popen giving parent permission to read
    if((ptr=popen(shellCommand, "r")) != NULL){
        //grabs BUFSIZ bytes from the ptr pipe
        while(fgets(buffer, BUFSIZ, ptr) != NULL)
            (void)printf("%s",buffer);//print out the results of buffer
    }
    pclose(ptr);
    free(shellCommand);
    exit(0);
}
