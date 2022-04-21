#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

struct pair{
    int freq;
    char val;
    struct pair *next;
};

void printQueue(struct pair *curr){
    while(curr!=NULL){
        printf("%c:%d\n",curr->val,curr->freq);
        curr=curr->next;
    }
}

/*
 * We must utilize the address of the pair structure instead of storing it into another
 * temporary variable to be returned. This will modify it directly which is what is
 * needed to build priority queue which is required to build the huffman coding tree
 */
void push(struct pair** start,int frequency,char value){
    //stores the address into a temporary storage space
    struct pair* curr = (*start);

    //constructs the new element to be push into the pQueue
    struct pair* newElement=malloc(sizeof(struct pair));
    newElement->next=NULL;
    newElement->val=value;
    newElement->freq=frequency;

    //if our frequency is a higher priority (higher frequency) than the head node it will replace it as the starting node
    if((*start)->freq>frequency||(*start)==NULL){
        newElement->next=(*start);
        (*start)=newElement;
    }
    //otherwise it will find its place to be put into the queue based on its frequency 
    else{
        while(curr->next!=NULL&&curr->next->freq<frequency)
            curr=curr->next;
        newElement->next=curr->next;
        curr->next=newElement;
    }
}

int main(int argc,char *argv[]){
    //checks that an arguement has been passed 
	if(argc!=2){
        printf("Error!\n");
        exit(1);
    }

    //opens the file and opens it (if not sends an error message and )
    int file=open(argv[1],O_RDONLY);
    if (file<0){
        printf("Open Error!\n");
        exit(2);
    }

    int rbyte;
    char b;

    //makes sure the given file isn't empty
    if((rbyte=read(file,&b,1))<0){
    	printf("Error! File Empty!\n");
    	close(file);
    	exit(3);
    }

    //this portion finds the values and their frequencies and stores them in a dynamic array
    struct pair *list=malloc(sizeof(struct pair));
    int listLen=1;
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
        	list=realloc(list,(listLen+1)*sizeof(struct pair));
            list[listLen].val=b;
            list[listLen++].freq=1;
        }
    }

    //temporary print out to test the frequency array
    for(int i=0;i<listLen;i++)
        printf("%c:%d\n",list[i].val,list[i].freq);

    //creates the priority queue to put all of these
    struct pair *pQueue=malloc(sizeof(struct pair));
    for(int i=0;i<listLen;i++)
        push(&pQueue,list[i].freq,list[i].val);
    free(list);

    printQueue(pQueue); //temporary print out to test the elements of the priority queue

    //these lines are where the compress and creatHuffTree command

    //this portion frees the memory of the priority queue 
    while(pQueue->next!=NULL){
        struct pair *pop=pQueue;
        pQueue=pQueue->next;
        free(pop);
    }

    close(file);
    exit(0);
}
