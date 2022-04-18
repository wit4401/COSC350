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

struct node{
    struct node *parent;
    struct node *left;
    struct node *right;
    struct pair info;
};

node *creatHuffTree(struct pair *list, int len){
}

void compress(int fd,struct huffNode *tree){
}

void uncompress(int fd,struct huffNode *tree){
}

void pairPush(){
}