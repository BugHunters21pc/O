#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
        int fd1,fd2,i;
        char buff[2];
        char *a1=argv[1],*a2 = argv[2];
        fd1 = open(a1,O_RDONLY,0777);
        fd2 = creat(a2,0777);
        if(fd1==-1){
                printf("\nError in openning a File.");
        }
        else{
        while(i=read(fd1,&buff[0],1)){
                write(fd2,&buff[0],1);
        }
        close(fd1);
        close(fd2);
        remove(a1);
        }
        return 0;

}
