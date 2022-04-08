#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

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
    struct pair *list=malloc(sizeof(struct pair));
    if(read(file,&b,1)>0){
	int listLen=1;
    	list[0].val=b;
    	list[0].freq=1;
    }
    else{
    	printf("Error! File Empty!\n");
	free(list);
    	close(file);
    	exit(3);
    }
    while((rbyte=read(file,&b,1))>0){
        int add=1;
        for(int i=0;i<listLen;i++){
            if(list[i].val==b){
                list[i].freq++;
                add=0;
            }
        }
        if(add){
        	list=realloc(list,(listLen+1)*sizeof(struct pair));
            list[listLen].val=b;
            list[listLen++].freq=1;
        }
    }
    
    //temporary sorting of the frequency array until implement the much more efficient priority queue
    for(int i=0;i<listLen-1;i++){
    	int min=i;
    	for(int j=i+1;j<listLen;j++){
    		if(list[min].freq>list[j].freq)
    			min=j;
    	}
    	int fTemp=list[i].freq;
    	char vTemp=list[i].val;
    	list[i].freq=list[min].freq;
    	list[i].val=list[min].val;
    	list[min].freq=fTemp;
    	list[min].val=vTemp;
    }
    /*
    for(int i=0;i<listLen;i++)
    	printf("Value: %c\nFrequency: %d\n\n",list[i].val,list[i].freq);
    */
    
    //compress(file,creatHuffTree(list,listLen));
    
    free(list);
    close(file);
    exit(0);
}
