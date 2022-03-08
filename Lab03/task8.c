#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int len(int dig){
    if(dig>=100)
        return 3;
    if(dig>=10)
        return 2;
    return 1;     
}

int main(int argc,char *argv[]){
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
    
    char b;//singular byte
    int rbyte;//readbytes

    //reading contents of the file
    while((rbyte=read(fileIn,&b,1)>0)){
        int num = (int) b;//conversion of char into an int (ascii form)       
        int length=len(num);//grabs the length of the number
        int newB[length];//the buffer containing the digits
        
        //loops to put all the digits in the buffer
        for(int i=length-1;i>=0;i--){           
            newB[i]=num % 10 + '0';//makes it so they are characters
            num=num/10;//moves the digit down by one
        }
        //loops to put the ascii numbers into the file (for some reason I couldnt get it to work with the newB).
        for(int i=0;i<length;i++){
            char b=newB[i];//stores a byte into a smaller buffer
            write(fileOut,&b,1);//writes the digits into the file
        }
        write(fileOut," ",1);//writes a space to seperate each ascii number in the file
    }

    //closes the open files
    close(fileIn);
    close(fileOut);
    exit(0);
}

