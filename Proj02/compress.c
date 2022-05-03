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
    umask(0000);
    int file;
    FILE *compFile; 
    file=open(argv[1],O_RDONLY);
    if (file<0){
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
    
    struct treeNode *huffTree=creatTree(pQueue);//creates an stores the huffTree to be used in the compression process

    /*
    int *codes=calloc(listLen,sizeof(int));
    puts("Tree Node Info (Inorder Traversal):");
    printTreeNodes(huffTree);//temporary function to print the Tree Node info via InOrder Traversal
    printcodes(huffTree,codes,0);//temporary function to print out all codes for each character in the file according to the tree
    free(codes);
    */

    //opens the file for the data to be stored into and compresses the file  
    compFile=fopen("compressed","w");
    if (compFile<0){
        printf("Open Error!\n");
        exit(3);
    }

    compress(huffTree,file,compFile);
    
    deleteTree(&huffTree);
    close(file);//closes the original file
    fclose(compFile);
    exit(0);
}