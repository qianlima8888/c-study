#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

int main()
{
    unlink("UNIX.domain");
    
    //创建socket
    int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1){
        perror("socket");
        return -1;
    }

    //绑定
    struct sockaddr_un addr;
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, "UNIX.domain");
    int res = bind(sockfd,(struct sockaddr *)&addr, sizeof(addr));
    if (res == -1){
        perror("bind"), exit(-1);
        close(sockfd);
        unlink("UNIX.domain");
        return -1;
    }
    printf("绑定成功\n");

    //监听
    printf("开始监听...\n");
    res = listen(sockfd, 1);
    if(res<0){
     perror("cannot listen sockfd");
     close(sockfd);
     unlink("UNIX.domain");
     return -1;
    }

    //连接客户端
    struct sockaddr_un client_addr;  
    socklen_t len = sizeof(client_addr);  
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &len);

    printf("已连接\n");

    //读取数据
    char buf[100] = {};
    res = read(client_sockfd, buf, 100);
    printf("读到了%d字节，内容：%s\n", res, buf);
    close(sockfd);
    return 0;
}