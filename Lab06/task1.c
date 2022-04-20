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

extern char **environ; //adds the environmental variables to the program

char *mygetenv(const char *name){
    //This portion of the program loops through until it finds a variable name that is equivalent
    for(int i=0;environ[i]!=NULL;i++){
        int check=1;
        for(int j=0;environ[i][j]!='=';j++){
            if(environ[i][j]!=name[j]){
                check=0;
                break;
            }
        }
        //if the upper portion found that the current variable name is equivalent it grabs everthing to the
        //left of the '=' sign
        if(check){
            char *result=malloc(sizeof(char));
            int len=0;
            int ind=1;
            int start=0;
            while(environ[i][len]!='\0'){
                if(environ[i][len-1]=='=')
                    start=1;
                if(start){
                    if(result[0]=='\0')
                        result[0]=environ[i][len];
                    else{
                        result=realloc(result,(len+1)*sizeof(char));
                        result[ind++]=environ[i][len];
                    }
                }
                len++;
            }
            return result; //returns the result
        }
    }
    return "Environment Variable not found!"; //returns if it loops through the entirety of the variables and comes up with nothing
}

// Main function to test the mygetenv() 
int main(int argc,char *argv[]){
	puts("getenv() results:");
    printf("%s: %s\n",argv[1],getenv(argv[1]));

    puts("");

	puts("mygetenv() test results:");
    printf("%s: %s\n",argv[1],mygetenv(argv[1]));
    exit(0);
}
