#include<stdio.h>
#include<string.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#define UNIX_DOMAIN "UNIX.domain"

int main(){
    int connect_fd;
    int ret;
    char send_buff[1024];
    int i;
    static struct sockaddr_un srv_addr;

    // creat unix socket
    connect_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (connect_fd < 0)
    {
        perror("cannot creat socket");
        return -1;
    }


    srv_addr.sun_family = AF_UNIX;
    strcpy(srv_addr.sun_path, UNIX_DOMAIN);


    //connect server
    printf("开始连接服务器");
    ret = connect(connect_fd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
    if (ret < 0)
    {
        perror("cannot connect server");
        close(connect_fd);
        return -1;
    }

    printf("服务器连接成功，准备发送消息");
    //发送的消息
    memset(send_buff, 0, 1024);
    strcpy(send_buff, "message from client\0");

    
    //send info server
    write(connect_fd, send_buff, sizeof(send_buff));
    close(connect_fd);
    return 0;
}
