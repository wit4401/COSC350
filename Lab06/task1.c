/*********************
|    Lab 6 Task 5    |
|    Will Townsend   |
|    April  2022     |
*********************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

extern char **environ;

char *mygetenv(const char *name){
    char **envVars=environ;
    int check;

    while(*envVars!=NULL){
        check=1;
        int i=0;
        while(**envVars!='='){
            printf("%c",**envVars++);
        }
        puts("");
        *envVars++;    	
    }
    return "Environment Variable not found!";
}

int main(){
	puts("getenv() results:");
    printf("HOME: %s\n",getenv("HOME"));
    printf("USER: %s\n",getenv("USER"));
    printf("PWD: %s\n",getenv("PWD"));
    printf("SHELL: %s\n",getenv("SHELL"));
    printf("LOGNAME: %s\n",getenv("LOGNAME"));

    puts("");

	puts("mygetenv() test results:");
    printf("%s\n",mygetenv("HOME"));
    printf("%s\n",mygetenv("USER"));
    printf("%s\n",mygetenv("PWD"));
    printf("%s\n",mygetenv("SHELL"));
    printf("%s\n",mygetenv("LOGNAME"));

    exit(0);
}
