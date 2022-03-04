#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int ascii(char c);

int main(int argc,char *argv[]){
    if(argc!=3){
        write(2,"Error! Please pass two arguements.\n",36);
        exit(2);
    }
    int fileIn=open(argv[1],O_RDONLY);
    int fileOut=open(argv[2],O_CREAT | O_RDWR, 0666);
    if(fileIn==-1 || fileOut==-1){
        write(2,"Error! Cannot open file.\n",26);
        exit(1);  
    }
    
    int buffer[1];
    int rbyte;
    while((rbyte=read(fileIn,buffer,1)>0)){
        buffer[0]=ascii(buffer[0]);       
        write(fileOut,buffer,rbyte);
        write(fileOut," ",1);
    }
    exit(0);
}

int ascii(char c){  
    return c;
}

