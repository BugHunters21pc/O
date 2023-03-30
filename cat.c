#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    int fd1,i;
    char buff[2];

  for(int j=1;j<argc;j++){
    fd1 = open(argv[j],O_RDONLY,0777);
    if(fd1==-1)
        printf("Error.");
    else
    {
        while(i=read(fd1,&buff[0],1)){
            printf("%c",buff[0]);
        }
    }
    close(fd1);
 }

    return 0;
}
