/* 进程一：读有名管道*/
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>  
#include<fcntl.h>  
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char const *argv[])
{
    char s[ ] = "class!\n";
    char nu[80];
    unlink("myfifo");
    mkfifo("myfifo",0666); 
    int fd = open("myfifo",O_RDWR);  
    write(fd,s,sizeof(s)); 
    //read(fd,nu,80);
    //printf("%s",nu);
    close(fd);
    //fclose(in_file);
}
