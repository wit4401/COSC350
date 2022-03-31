#include<stdio.h>
#include<stdlib.h>

struct pair{
    int freq;
    char val;
};

struct node{
	struct node *left;
	struct node *right;
    struct pair info;
};
