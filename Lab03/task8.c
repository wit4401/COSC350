#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

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
        write(fileOut,&num,rbyte);//writes into the file the ascii equivalent (ERROR! does not give desired output)
        printf("%d ",num);//tests the actual conversion
    }
    puts("");

    //closes the open files
    close(fileIn);
    close(fileOut);
    exit(0);
}

