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

struct qNode *newPair(struct pair newInfo){
    struct qNode *newNode=malloc(sizeof(struct qNode));
    newNode->next=NULL;
    newNode->info=newInfo;
    return newNode;
}

//This function frees the memory allocated in the priority queue
void pop(struct qNode **start){
    struct qNode *pop=(*start);
    (*start)=(*start)->next;
    free(pop);
}

/*
 * We must utilize the address of the pair structure instead of storing it into another
 * temporary variable to be returned. This will modify it directly which is what is
 * needed to build priority queue which is required to build the huffman coding tree
 */
void push(struct qNode **start,struct qNode *newNode){
    if(newNode->info.freq < (*start)->info.freq){
        newNode->next=(*start);
        (*start)=newNode;
    }
    else{
        struct qNode *curr=(*start);
        while(curr->next != NULL && curr->next->info.freq < newNode->info.freq)
            curr=curr->next;
        newNode->next = curr->next;
        curr->next=newNode;
    }
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
    
    //creates the priority queue to put all of these
    struct qNode *pQueue=malloc(sizeof(struct qNode));
    for(int i=0;i<listLen;i++)
        push(&pQueue,newPair(list[i]));
    free(list);

    printQueue(pQueue); //temporary print out to test the elements of the priority queue

    //these lines are where the compress and creatHuffTree command 

    //this frees all allocated data in the priority queue 
    while((listLen--)>0)
        pop(&pQueue);

    close(file);//closes the original file
    exit(0);
}
