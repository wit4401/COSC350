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

struct nodePair{
    struct huffNode *parent;
    struct pair info;
};

struct huffNode{
    struct huffNode *parent;
    struct huffNode *left1;//left1 used for every huffNode excecpt the built node
    struct nodePair *left2; //left2 only used for the starting node
    struct nodePair *right;
    int tot;
};

huffNode *creatHuffTree(struct pair *list, int len){
    struct huffNode *curr=malloc(sizeof(struct huffNode));
    struct huffNode *startNode=malloc(sizeof(struct huffNode));
    curr->left2=malloc(sizeof(struct nodePair));
    curr->left2->pair=list[0];
    
    if(len>1){
        curr->right=malloc(sizeof(struct nodePair));
        curr->right->pair=list[1];
        curr->tot=curr->right->pair.freq+curr->left2->pair.freq;
        curr->parent=malloc(sizeof(struct huffNode));
        curr->parent->left1=curr;
        curr=curr->parent;
        for(int i=2;i<len;i++){
        	if(i!=len-1){
                curr->right=malloc(sizeof(struct nodePair));
                curr->right=list[i];

                curr->parent=malloc(sizeof(struct huffNode));
                curr->parent->left=curr;
                curr=curr->parent;
        	}
        	else{
                startNode->left1=malloc(sizeof(struct huffNode));
                startNode->left1=curr;
        		startNode->right=malloc(sizeof(struct nodePair));
                startNode->right=list[i];
                startNode->tot=startNode->right.freq+startNode->left.tot;

        	}
        }
        
    }
    else{
    	curr->tot=curr->left2->pair.freq;
    	return curr;
    }
    return startNode;
}

void compress(int fd,struct huffNode *tree){
}

void uncompress(int fd,struct huffNode *tree){
}