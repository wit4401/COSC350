#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/stat.h>
#include<sys/types.h>

//structure to construct represent a character-frequency pair
struct pair{
    int freq;
    char val;
};

//structure that represents a node on the tree
struct treeNode{
    struct treeNode *parent;
    struct treeNode *left;
    struct treeNode *right;
    struct pair pairInfo;
};

//allows us to construct a queue of the treeNode type
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

//frees the data from the huffman coding tree
void deleteTree(struct treeNode **root){
    if((*root)->left!=NULL)
        deleteTree(&(*root)->left);
    if((*root)->right!=NULL)
        deleteTree(&(*root)->right);
    free((*root));
}

//This function frees allocated memory of the appropriate element
void pop(struct qNode **start){
    struct qNode *popped=(*start);
    (*start)=(*start)->next;
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

//function creates the huffman coding tree to be utilized in the compression process
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

//this allows us to put the code for an associated with its proper value (is a recursive function and utilizes
//the address to directly affect the array and its length
void searchHuffTree(struct treeNode *root,int *arr,int top,char cmp,int *arrLen){
    if(root->left!=NULL){
        if((*arrLen)==0){
            arr[top]=0;
            searchHuffTree(root->left,arr,top+1,cmp,arrLen);
        }
    }
    if(root->right!=NULL){
        if((*arrLen)==0){
            arr[top]=1;
            searchHuffTree(root->right,arr,top+1,cmp,arrLen);
        }
    }
    if(root->left==NULL && root->right==NULL){
    	if(cmp==root->pairInfo.val)
	        *arrLen=top;
    }
}

//actually writes the necessary binaary data into the file to create the compressed file
//using a long unsigned int
void compress(struct treeNode *root, int fdIn, FILE *fdOut){
    int rbytes;
    char b;
    int codeLen=0;
    int code[999999];
    unsigned long int pack=0;
    int packLen=sizeof(pack);
    int numOfBits=packLen-1;
    lseek(fdIn,0,SEEK_SET);

    while((rbytes=read(fdIn,&b,1))>0){
        searchHuffTree(root,code,0,b,&codeLen);
        for(int i=0;i<codeLen;i++){
            if(code[i]==1)
                pack=pack|(1UL<<numOfBits);
            numOfBits--;
            if(numOfBits<0){
                fwrite(&pack,1,1,fdOut);
                numOfBits=packLen-1;
                pack=0;
            }
        }
        codeLen=0;
    }
}

//unbuilt uncompressed function
void uncompress(int fd,struct treeNode *root){
}