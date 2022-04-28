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
    struct qNode *popped=(*start);
    (*start)=(*start)->next;
    free(popped->tNode);
    free(popped);
}

void printQueue(struct qNode *start){
    struct qNode *curr=start;
    while(curr!=NULL){
        printf("%c:%d\n",curr->tNode->pairInfo.val,curr->tNode->pairInfo.freq);
        curr=curr->next;
    }
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
        newQNode->tNode=malloc(sizeof(struct treeNode));
        newQNode->next=NULL;
        newQNode->tNode->pairInfo.val='\0';

        newQNode->tNode->left=curr->tNode;
        int lFreq=curr->tNode->pairInfo.freq;
        pop(&curr);

        newQNode->tNode->right=curr->tNode;
        int rFreq=curr->tNode->pairInfo.freq;
        pop(&curr);

        newQNode->tNode->pairInfo.freq=rFreq+lFreq;
        newQNode->tNode->parent=NULL;
        newQNode->tNode->right->parent=newQNode->tNode;
        newQNode->tNode->left->parent=newQNode->tNode;

        if(curr!=NULL)
            push(&curr,newQNode);
        else
            curr=newQNode;
    }
    return curr->tNode;
}

void printTreeNodes(struct treeNode *root){
    if(root->left!=NULL){
        printTreeNodes(root->left);
        printf("Node info: %c:%d",root->pairInfo.val,root->pairInfo.freq);
        printf("Parent info: %c:%d",root->parent->pairInfo.val,root->parent->pairInfo.freq);
        printf("Right Child info: %c:%d",root->right->pairInfo.val,root->right->pairInfo.freq);
        printf("Left Child info: %c:%d",root->left->pairInfo.val,root->left->pairInfo.freq);
    }
    if(root->right!=NULL){
        printTreeNodes(root->right);
        printf("Node info: %c:%d",root->pairInfo.val,root->pairInfo.freq);
        printf("Parent info: %c:%d",root->parent->pairInfo.val,root->parent->pairInfo.freq);
        printf("Right Child info: %c:%d",root->right->pairInfo.val,root->right->pairInfo.freq);
        printf("Left Child info: %c:%d",root->left->pairInfo.val,root->left->pairInfo.freq);
    }
    else{
        printf("Node info: %c:%d",root->pairInfo.val,root->pairInfo.freq);
        printf("Parent info: %c:%d",root->parent->pairInfo.val,root->parent->pairInfo.freq);
        printf("Right Child info: %c:%d",root->right->pairInfo.val,root->right->pairInfo.freq);
        printf("Left Child info: %c:%d",root->left->pairInfo.val,root->left->pairInfo.freq);
    }
}

void printcodes(struct treeNode *root,int code[],int top){
    if(root->left!=NULL){
        code[top]=0;
        printcodes(root->left,code,top++);
    }
    if(root->right!=NULL){
        code[top]=1;
        printcodes(root->right,code,top++);
    }
    if(root->left==NULL && root->right==NULL){
        printf("%c:",root->pairInfo.val);
        for(int i=0;i<top;i++)
            printf("%d",code[i]);
        puts("");
    }
}

void compress(int fd,struct treeNode *root){
}

void uncompress(int fd,struct treeNode *root){
}
