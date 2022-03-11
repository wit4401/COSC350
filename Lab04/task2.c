/*********************
|    Lab 4 Task 2    |
|    Will Townsend   |
|    March  2022     |
*********************/
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
    
    //reads each character in the file to check if they are digits if so convert and utilize in the variable 'sum'
    while((rbyte=read(file,&b,1))>0)
        if (isdigit((int) b)!=0)
            sum = sum * 10 + b -'0';
    sum+=10;//adds ten to sum
    convIntToStr(newBuff,sum);//calls the function to convert the integer into a string
    write(1,newBuff,sizeof(newBuff));//writes the embedded integer onto the standard output
    puts("");
    exit(0);
}
