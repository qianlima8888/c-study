#include<unistd.h>
#include<sys/types.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
//#define INPUT 0
//#define OUTPUT 1

int main(int argc, char const *argv[])
{
    int file_descriptors[2];//[0]代表读，[1]代表写
    //定义子进程号
    pid_t pid;
    char buf[256] = {0};
    int returned_count;
    //创建无名管道
    pipe(file_descriptors);
    //创建子进程
    if((pid = fork()) == -1)
    {
        std::cout<<"error in fork/n";
        return -1;
    }

    //执行子进程
    if(pid == 0)
    {
        //写的时候要关闭读
        close(file_descriptors[0]); 
        write(file_descriptors[1], "test data", strlen("test data"));  
    } 
    //执行父进程      
    else { 
        
        printf("in the spawning (parent) process...\n"); 
        /*父进程从管道读取子进程写的数据，关闭管道的写端*/ 
        close(file_descriptors[1]); 
        returned_count = read(file_descriptors[0], buf, sizeof(buf)); 
        printf("%d bytes of data received from spawned process: %s\n", returned_count, buf); 
    }
    return 0;
}
