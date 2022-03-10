#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int intArrToInt(int digits[], int length){
    int finalNum=0;
    for(int i=0;i<length;i++){
        finalNum = finalNum * 10 + digits[i];
    }
    return finalNum;
}

int main(int argc, char *argv[]){
    //error checks the arguements    
    if(argc!=3){
        write(2,"Error! Please pass two arguements.\n",36);
        exit(2);
    }
    
    umask(000);//allows permissions to be set to any for usr, grp, oth
    int fileIn=open(argv[1],O_RDONLY);//opens input file determined by the first arguement
    int fileOut=open(argv[2],O_CREAT | O_RDWR, 0666);//creates the output file (name determined by second command line arguement
    
    //error check for files
    if(fileIn==-1 || fileOut==-1){
        write(2,"Error! Cannot open file.\n",26);
        exit(1);  
    }
    
    char b;
    int rbyte;
    int *num;
    int index=0;
    while((rbyte=read(fileIn,&b,1))>0){
        if(b != ' ')
            num[index++]= b - '0';
        else{
           //printf("%d ",intArrToInt(num,index+1));
            char newB = (char) intArrToInt(num,index);
            write(fileOut,&newB,1);
            index=0;
        }
    }
    close(fileIn);
    close(fileOut);
    exit(0);
}
