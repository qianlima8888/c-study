#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>  
#include<fcntl.h>  
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
    int out_file;
    char s[ ] = "room!\n";
    char buf[80];
    out_file = open("myfifo",O_RDWR);
    read(out_file,buf,80);
    printf("%s",buf);
    //write(out_file,s,sizeof(s));
    close(out_file);
}