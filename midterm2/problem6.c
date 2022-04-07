#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int var;
    pid_t pid;
    
    var=888;
    printf("Before the fork\n");
    
    pid=fork();
    
    if(pid==0)
        var++;
    else if (pid>0)
        var--;
    else
        printf("fork failed\n");
    
    printf("pid=%d, var=%d\n",getpid(),var);
    return 0;
}
