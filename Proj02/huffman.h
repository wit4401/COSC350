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
	struct huffNode *left;
	struct nodePair *right;
    struct pair info;
};

struct huffNode{
    struct huffNode *parent;
    struct nodePair *right;
    int tot;
};

struct startNode{
    struct huffNode *parent;
    struct nodePair *left;
    struct nodePair *right;
};

huffNode *creatHuffTree(struct pair *list){
    return NULL;
}

void compress(int fd,struct huffNode *tree){
}

void uncompress(int fd,struct huffNode *tree){
}