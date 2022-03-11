#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

//function converts the arr of digits into a singular int
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
    
    char b;//singular byte buffer
    int rbyte;//read bytes
    int *num;//int array containing the digits
    int index=0;//an index for the num array
    while((rbyte=read(fileIn,&b,1))>0){
        if(b != ' ')//if b is a number
            num[index++]= b - '0';//inserts into the array
        else{
            //this means
            char newB = (char) intArrToInt(num,index);//casts the integer as a character
            write(fileOut,&newB,1);//writes the character into the file
            index=0;//resets the index for the next set of digits
        }
    }
    //close both of the files that were opened
    close(fileIn);
    close(fileOut);
    exit(0);
}
