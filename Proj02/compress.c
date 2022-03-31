#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

struct pair{
    int freq;
    char val;
};

int main(int argc,char *argv[]){
	if(argc!=2){
        printf("Error!\n");
        exit(1);
    }
    int file=open(argv[1],O_RDONLY);
    if (file<0){
        printf("Open Error!\n");
        exit(2);
    }
    int rbyte;
    char b;
    struct pair *list;
    int listLen=1;
    read(file,&b,1);
    list[0].val=b;
    list[0].freq=1;
    while((rbyte=read(file,&b,1))>0){
        int add=1;
        for(int i=0;i<listLen;i++){
            if(list[i].val==b){
                list[i].freq++;
                add=0;
            }
        }
        if(add){
            list[listLen].val=b;
            list[listLen++].freq=1;
        }
    }
    for(int i=0;i<listLen;i++)
        printf("Value: '%c'\nFrequency: %d\n",list[i].val,list[i].freq);
    exit(0);
}
