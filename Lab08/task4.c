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
    char* shellCommand;
    for(int i=1; i<argc; i++){
        size+=strlen(argv[i]);
    }

    shellCommand=malloc(size*sizeof(char));

    for(int i=1; i<argc; i++)
        sprintf(shellCommand, "%s %s", shellCommand, argv[i]);

    char buffer[BUFSIZ];
    FILE* ptr;
    if((ptr=popen(shellCommand, "r")) != NULL){
        while(fgets(buffer, BUFSIZ, ptr) != NULL)
            (void)printf("%s",buffer);
    }
    pclose(ptr);
    exit(0);
}
