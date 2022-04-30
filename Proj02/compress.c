#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include"huffman.h"

int main(int argc,char *argv[]){
    //checks that an arguement has been passed 
	if(argc!=2){
        printf("Error!\n");
        exit(1);
    }

    //opens the file and opens it (if not sends an error message and exits program)
    int file=open(argv[1],O_RDONLY);
    int compFile=open("compressed",O_CREAT | O_TRUNC | O_RDWR);
    if (file<0||compFile){
        printf("Open Error!\n");
        exit(2);
    }

    //this portion finds the values and their frequencies and stores them in a dynamic array
    struct pair *list=malloc(sizeof(struct pair));
    int rbyte;
    char b;
    int listLen=0;
    while((rbyte=read(file,&b,1))>0){
        int add=1;
        for(int i=0;i<listLen;i++){
            if(list[i].val==b){
                list[i].freq++;
                add=0;
                break;
            }
        }
        if(add){
        	list=realloc(list,(listLen+1)*sizeof(struct pair));
            list[listLen].val=b;
            list[listLen++].freq=1;
        }
    }
    //creates the priority queue to put all of these 
    struct qNode *pQueue=newPair(list[0]);
    for(int i=1;i<listLen;i++)
        push(&pQueue,newPair(list[i]));
    free(list);
    
    //these lines are where the compress and creatHuffTree command 
    int *codes=calloc(listLen,sizeof(int));
    struct treeNode *huffTree=creatTree(pQueue);
    puts("Tree Node Info (Inorder Traversal):");
    printTreeNodes(huffTree);
    printcodes(huffTree,codes,0);

    compress(compFile,file,huffTree);
    
    deleteTree(&huffTree);
    close(file);//closes the original file
    close(compFile)
    exit(0);
}
