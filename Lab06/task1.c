#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

extern char **environ;

char *mygetenv(const char *name){
    char **envVars=environ;
    int check=1;
    
    while(*envVars!=NULL){
    	char *varName=malloc(sizeof(char));
    	int len=1;
    	varName[0]=**envVars++;
    	while(**envVars!='='){
    		varName=realloc(varName,(++len)*sizeof(char));
    		strcat(varName,&**envVars);
    		**envVars++;
    	}
    	if(varName==name){
    		free(varName);
    		return *envVars;
    	}
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
    return 0;
}
