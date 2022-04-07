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
    for(int i=0;i<n;i++)
        randStr[i]=(char) rand()%128-'a';
    printf("%s\n",randStr);
    free(randStr);
    exit(0);
}
