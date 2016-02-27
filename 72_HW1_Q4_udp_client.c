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
    unsigned int serversock_len;
    char msg[] = "hello server";
    char recv_msg[100];
    if (argc != 2){
	perror("provid hostname as argument");
	exit(1);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL){
	perror("failed on gethostbyname");
	exit(1);
    }
    mysocket = socket(AF_INET, SOCK_DGRAM,0); //tcp connection
    bzero((char *) &serversockaddr, sizeof(serversockaddr)); 
    serversockaddr.sin_family = AF_INET;
    inet_aton(server->h_addr, &serversockaddr.sin_addr);
    serversockaddr.sin_port = htons(PORT_NUM);
    serversock_len = sizeof(serversockaddr);
    // send a msg to server and expect a msg from server
    sendto(mysocket, &msg,sizeof(msg),0, (struct sockaddr *)&serversockaddr, serversock_len);

    bzero(recv_msg,100);
    recvfrom(mysocket, &recv_msg, sizeof(recv_msg),0, (struct sockaddr *)&serversockaddr, &serversock_len);
    printf("got msg back from server: %s\n",recv_msg);
    close(mysocket);
    return 0;
}
