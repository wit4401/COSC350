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

struct treeNode{
    struct treeNode *parent;
    struct treeNode *left;
    struct treeNode *right;
    struct pair pairInfo;
};

struct qNode{
    struct qNode *next;
    struct treeNode *tNode;
};

//function that constructs a new pair for the priority queue
struct qNode *newPair(struct pair newInfo){
    struct qNode *newNode=malloc(sizeof(struct qNode));
    newNode->next=NULL;
    newNode->tNode=malloc(sizeof(struct treeNode));
    newNode->tNode->pairInfo=newInfo;
    newNode->tNode->parent=NULL;
    newNode->tNode->right=NULL;
    newNode->tNode->left=NULL;
    return newNode;
}

//This function frees allocated memory of the appropriate element
void pop(struct qNode **start){
    struct qNode *popped=curr;
    curr=curr->next;
    free(popped);
}

//We must utilize the address of the pair structure instead of storing it into another
//temporary variable to be returned. This will modify it directly which is what is
//needed to build priority queue which is required to build the huffman coding tree
void push(struct qNode **start,struct qNode *newNode){
    if(newNode->tNode->pairInfo.freq < (*start)->tNode->pairInfo.freq){
        newNode->next=(*start);
        (*start)=newNode;
    }
    else{
        struct qNode *curr=(*start);
        while(curr->next != NULL && curr->next->tNode->pairInfo.freq < newNode->tNode->pairInfo.freq)
            curr=curr->next;
        newNode->next = curr->next;
        curr->next=newNode;
    }
}

struct treeNode *creatTree(struct qNode *list){
    struct qNode *curr=list;
    while(curr->next!=NULL){
        struct qNode *newQNode=malloc(sizeof(struct qNode));
        newQNode->tNode->pairInfo.val='\0';

        newQNode->tNode->left=curr->tNode;
        int lFreq=newQNode->tNode->left->pairInfo.freq;
        pop(curr);

        newQNode->tNode->right=curr->tNode;
        int rFreq=newQNode->tNode->right->pairInfo.freq;
        pop(curr);

        newQNode->tNode->pairInfo.freq=rFreq+lFreq;
        newQNode->tNode->parent=NULL;
        newQNode->tNode->right->parent=newQNode;
        newQNode->tNode->left->parent=newQNode;

        if(curr!=NULL)
            push(&curr,newQNode);
        else
            curr=newQNode;
    }
    return curr->tNode;
}

void compress(int fd,struct treeNode *root){
}

void uncompress(int fd,struct treeNode *root){
}
