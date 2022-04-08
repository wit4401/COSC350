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
	if(len==0)
		return NULL;
    struct huffNode *fTree=malloc(sizeof(struct huffNode));
    fTree->left2=malloc(sizeof(struct nodePair));
    fTree->right=malloc(sizeof(struct nodePair));
    fTree->left2->pair.freq=list[0].freq;
    fTree->left2->pair.val=list[0].val;
    if(len>1){
    	
    }
    else
    	fTree->tot=fTree->left2->pair.freq;
    return fTree;
}

void compress(int fd,struct huffNode *tree){
}

void uncompress(int fd,struct huffNode *tree){
}