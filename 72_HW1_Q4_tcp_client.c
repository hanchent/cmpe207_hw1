#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT_NUM 8000  //pick 8000 as the port number

int main(int argc, char *argv[])
{
    int mysocket;
    int connect_rtn;
    struct hostent *server;
    struct sockaddr_in serversockaddr;
    char msg[100];
    if (argc != 2){
	perror("provid hostname as argument");
	exit(1);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL){
	perror("failed on gethostbyname");
	exit(1);
    }
    mysocket = socket(AF_INET, SOCK_STREAM,0); //tcp connection
    bzero((char *) &serversockaddr, sizeof(serversockaddr)); 
    serversockaddr.sin_family = AF_INET;
    inet_aton(server->h_addr, &serversockaddr.sin_addr);
    serversockaddr.sin_port = htons(PORT_NUM);
    connect_rtn = connect(mysocket, (struct sockaddr *)&serversockaddr, sizeof(serversockaddr));
    if(connect_rtn != 0){
	perror("failed on connecting");
	exit(1);
    }
    bzero(msg,100);
    read(mysocket, &msg, sizeof(msg));
    printf("%s\n",msg);
    close(mysocket);
    return 0;
}
