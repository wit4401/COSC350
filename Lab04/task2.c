#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>

/************************************************
Convert integer to string
Params: x is the int to be converted,
        str is the string into which to write
Returns: length of the string
**************************************************/
int convIntToStr(char * str, int x){
    sprintf(str, "%d", x);
    return (strlen(str));
}

int main(int argc,char *argv[]){
    if (argc!=2){
        puts("Must pass ONE arguement!");
        exit(1);
    }
    int file;
    if (file=open(argv[1],O_RDONLY)==-1){
        puts("Error could not open file!");
        exit(2);
    }
    char *b;
    char readByte;
    int rbyte;
    int index=0;
    
    while((rbyte=read(file,&readByte,1))>0)
        b[index++]=readByte;
    
    int num=0;
    for(int i=0;i<index;i++)
        num = num * 10 + b[i] - '0';
    printf("%d",num);
    exit(0);
}
