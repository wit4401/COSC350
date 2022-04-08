#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>

int main(){
    int n;
    printf("Please enter a value: ");
    scanf("%d",&n);
    srand(time(0));
    char *randStr=calloc(n,sizeof(char));
    for(int i=0;i<n;i++){
    	int min,max;
    	if(rand()%2==0){
        	min='A';
        	max='Z';
        }
        else{
        	min=(int)'a';
        	max=(int)'z';
        }
        randStr[i]=(char) rand()%max+min;
     }
    printf("%s\n",randStr);
    free(randStr);
    exit(0);
}
