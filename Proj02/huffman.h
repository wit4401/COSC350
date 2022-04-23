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
    struct pair info;
    struct qNode *next;
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

//We must utilize the address of the pair structure instead of storing it into another
//temporary variable to be returned. This will modify it directly which is what is
//needed to build priority queue which is required to build the huffman coding tree 
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

struct treeNode{
    struct node *parent;
    struct node *left;
    struct node *right;
    struct pair info;
};

struct treeNode *creatHuffTree(struct pair *list, int len){
    return NULL;
}

void compress(int fd,struct treeNode *tree){
}

void uncompress(int fd,struct treeNode *tree){
}

void pairPush(){
}
