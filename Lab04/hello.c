#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
/****************
 Lab 4 Task 4
 Will Townsend
*****************/
int main(){
    //creates a directory Dir1 in home
    if (mkdir("/mnt/linuxlab/home/wtownsend2/Dir1",0755)==-1)
        puts("Error");
    //creates a directory Dir2 in home
    if (mkdir("/mnt/linuxlab/home/wtownsend2/Dir2",0755)==-1)
        puts("Error");
    //creates a directory Dir21 in Dir2
    if (mkdir("/mnt/linuxlab/home/wtownsend2/Dir2/Dir21",0755)==-1)
        puts("Error");
    //creates a file excutable file hello in Dir21
    link("/mnt/linuxlab/home/wtownsend2/COSC350/Lab04/hello","/mnt/linuxlab/home/wtownsend2/Dir2/Dir21/hello");
    //creates a symbolic link to Dir21 in Dir1
    symlink("/mnt/linuxlab/home/wtownsend2/Dir2/Dir21","/mnt/linuxlab/home/wtownsend2/Dir1/toDir21");
    //creates a symbolic link to hello in Dir1
    symlink("/mnt/linuxlab/home/wtownsend2/Dir2/Dir21/hello","/mnt/linuxlab/home/wtownsend2/Dir1/toHello");
}
