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
    struct huffNode *root;
    curr->left2=malloc(sizeof(struct nodePair));
    curr->left2->info=list[0];

    //defines the parent node of left2
    curr->left2->parent=malloc(sizeof(struct huffNode));
    curr->left2->parent=curr;

    if(len>1){
        //creates the right value by grabbing the second pair in the 'pair' array
        curr->right=malloc(sizeof(struct nodePair));
        curr->right->info=list[1];

        curr->right->parent=malloc(sizeof(struct huffNode));
        curr->right->parent=curr;

        //computes the total and stores the information
        curr->tot=curr->right->info.freq+curr->left2->info.freq;
        for(int i=2;i<len;i++){
            if(i!=len-1){
                //creates the parent and assigns said parent's left node to the current node
                curr->parent=malloc(sizeof(struct huffNode));
                curr->parent->left1=curr;
                curr=curr->parent;

                //creates the right node and stores the pair into it
                curr->right=malloc(sizeof(struct nodePair));
                curr->right->parent=malloc(sizeof(struct huffNode));
                curr->right.info=list[i];
                curr->right->parent=curr;

                //computes the current total
                curr.tot = curr->left1.tot + curr->right.freq;
        	}
        	else{
                //stores information into the final root node
                root= (struct huffNode*) malloc(sizeof(struct huffNode));
                
                //stores curr into the left of the root node
                root->left1=malloc(sizeof(struct huffNode));
                root->left1=curr;

                //stores the final element to the right of root node
                root->right=malloc(sizeof(struct nodePair));
                root->right=list[i];
                right->parent=malloc(sizeof(struct huffNode));
                right->parent=root;

                //connects the root to the curr
                curr->parent=malloc(sizeof(struct huffNode));
                curr->parent=root;

                //computes the total for the root node
                root->tot=root->right.freq+startNode->left.tot;

        	}
        }
        
    }
    else{
    	curr->tot=curr->left2->info.freq;
    	return curr;
    }
    return startNode;
}

void compress(int fd,struct huffNode *tree){
}

void uncompress(int fd,struct huffNode *tree){
}