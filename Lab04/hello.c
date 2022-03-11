#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
    if (mkdir("/mnt/linuxlab/home/wtownsend2/Dir1",0755)==-1)
        puts("Error");
    if (mkdir("/mnt/linuxlab/home/wtownsend2/Dir2",0755)==-1)
        puts("Error");
    if (mkdir("/mnt/linuxlab/home/wtownsend2/Dir2/Dir21",0755)==-1)
        puts("Error");
    link("/mnt/linuxlab/home/wtownsend2/COSC350/Lab04/hello","/mnt/linuxlab/home/wtownsend2/Dir2/Dir21/hello");
    symlink("/mnt/linuxlab/home/wtownsend2/Dir2/Dir21","/mnt/linuxlab/home/wtownsend2/Dir1/toDir21");
    symlink("/mnt/linuxlab/home/wtownsend2/Dir2/Dir21/hello","/mnt/linuxlab/home/wtownsend2/Dir1/toHello");
}
