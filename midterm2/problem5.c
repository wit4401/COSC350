#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
    int check=1;
    int num=0;
    int nonNum=0;
    
    for(int i=1;i<argc;i++){
        for(int j=0;argv[i][j]!='\0';j++){
            if(!isdigit(argv[i][j])){
                nonNum++;
                check=0;
                break;
            }
        }
        if(check)
            num++;
        else
            check=1;
        printf("%s\n",argv[i]);
    }
    printf("Number Count: %d\n",num);
    printf("Non Number Count: %d\n",nonNum);
    exit(0);
}
