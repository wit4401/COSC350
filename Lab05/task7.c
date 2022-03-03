#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int strToInt(char str[]){
    int i=0;
    int sign=0;
    int num=0;

    if(str[0]=='-')
        sign=-1;
    if(sign==-1)
        i++;
    for(i;str[i]!='\0';i++)
        num=num*10 + str[i] - '0';
    if(sign==-1)
        num=-num;
    return num;
}

int main(int argc,char *argv[]){
    if(argc<2){
        printf("Please pass at least one arguement.\n");
        exit(1);
    }
    int sum=0;
    for(int i=1;i<argc;i++)
        sum+=strToInt(argv[i]);
    printf("Sum of the Digits: %d\n", sum);
    exit(0);
}
