#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <strings.h>
#define SERV_PORT  9999

int main(int argc,char **argv)
{
    int listenfd,connfd;
    pid_t  childpid,childpid2;
    socklen_t clilen;
    struct sockaddr_in cliaddr,servaddr;

    char buffer[1024] = {0};
    char *hello = "Hello from server";

    listenfd = socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl (INADDR_ANY);
    servaddr.sin_port = htons (SERV_PORT);

    bind(listenfd,  (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(listenfd,1000);

    clilen = sizeof(cliaddr);

    if( (childpid = fork()) == 0)
    {
        while(1)
        {
            connfd = accept(listenfd,(struct sockaddr *) &cliaddr,&clilen);
            printf("fork 1 is [%d],errno is %d\n",connfd, errno);

            int valread = read( connfd, buffer, 1024);
            printf("%s\n",buffer );
            send(connfd, hello , strlen(hello) , 0 );
            printf("Hello message sent\n");
        }
    }

    if( (childpid2 = fork()) == 0)
    {
        while(1){
            connfd = accept(listenfd,(struct sockaddr *) &cliaddr,&clilen);
            printf("fork 2 is [%d]，errno is %d\n",connfd, errno);

            int valread = read( connfd, buffer, 1024);
            printf("%s\n",buffer );
            send(connfd, hello , strlen(hello) , 0 );
            printf("Hello message sent\n");
        }
    }

    sleep(100);
    return 1;
}
