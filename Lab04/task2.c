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
    int file=open(argv[1],O_RDONLY);
    if (file==-1){
        puts("Error could not open file!");
        exit(2);
    }
    int rbyte;
    char b;
    char *newBuff;
    int sum=0;
    
    while((rbyte=read(file,&b,1))>0)
        if (isdigit((int) b)!=0)
            sum = sum * 10 + b -'0';
    sum+=10;
    convIntToStr(newBuff,sum);
    write(1,newBuff,sizeof(newBuff));
    puts("");
    exit(0);
}
