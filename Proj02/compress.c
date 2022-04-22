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

struct qNode{
    struct qNode *next;
    struct pair info;
};

void printQueue(struct qNode *start){
    struct qNode *curr=start;
    while(curr!=NULL){
        printf("%c:%d\n",curr->info.val,curr->info.freq);
        curr=curr->next;
    }
}

//This function frees the memory allocated in the priority queue  
void pop(struct qNode*& start){
}

struct qNode *newPair(struct pair newInfo){
    struct qNode newNode=malloc(sizeof(struct qNode));
    newNode->next=NULL;
    newNode->info=newInfo;
}

/*
 * We must utilize the address of the pair structure instead of storing it into another
 * temporary variable to be returned. This will modify it directly which is what is
 * needed to build priority queue which is required to build the huffman coding tree
 */
void push(struct qNode*& start,int frequency,char value){
}

int main(int argc,char *argv[]){
    //checks that an arguement has been passed 
	if(argc!=2){
        printf("Error!\n");
        exit(1);
    }

    //opens the file and opens it (if not sends an error message and exits program)
    int file=open(argv[1],O_RDONLY);
    if (file<0){
        printf("Open Error!\n");
        exit(2);
    }

    //this portion finds the values and their frequencies and stores them in a dynamic array
    struct pair *list=malloc(sizeof(struct pair));
    int rbyte;
    char b;
    int listLen=0;
    while((rbyte=read(file,&b,1))>0){
        int add=1;
        for(int i=0;i<listLen;i++){
            if(list[i].val==b){
                list[i].freq++;
                add=0;
                break;
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
    struct qNode *pQueue=malloc(sizeof(struct qNode));
    for(int i=0;i<listLen;i++)
        push(pQueue,list[i].freq,list[i].val);
    free(list);

    printQueue(pQueue); //temporary print out to test the elements of the priority queue

    //these lines are where the compress and creatHuffTree command 
    
    close(file);
    exit(0);
}
