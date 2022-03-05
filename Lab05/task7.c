/*
* Lab 3 Task 7
* COSC 350
* Will Townsend
*/
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

//function to convert a string of digits into an int
int strToInt(char str[]){
    int i=0;//increment variable (for loop)
    int sign=0;//used check sign case
    int num=0;//final number to be returned

    //checks if number is negative, adjusts sign variable accordingly
    if(str[0]=='-')
        sign=-1;
    //adds one to the increment variable to ignore
    if(sign==-1)
        i++;
    
    //loops through the digits converting each into their digit equivalent  
    /*
     * Given a char arr '123' the loops is as follow:
     * 0*10+'1'-'\0'=1 => 1*10+'2'-'\0'=12 => 12*10+'3'-'\0'= 123
     * This loop works for any set of digits in a character array.
    */    
    for(i;str[i]!='\0';i++)
        num=num*10 + str[i] - '0';
    //fixes num if '-' was found earlier    
    if(sign==-1)
        num=-num;
    //returns the final converted number
    return num;
}

int main(int argc,char *argv[]){
    //error checks the parameters (makes sure there is at leat one integer
    if(argc<2){
        printf("Please pass at least one arguement.\n");
        exit(1);
    }
    
    int sum=0;//initializes the sum
    //loops through all the arguements, converts them to integers, and adds them up    
    for(int i=1;i<argc;i++)
        sum+=strToInt(argv[i]);
    printf("Sum of the Digits: %d\n", sum);//prints the sum of numbers
    exit(0);
}
