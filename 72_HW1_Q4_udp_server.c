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

int main()
{
    int mysocket;
    int bind_rtn;
    struct sockaddr_in my_sockaddr, new_sockaddr;
    unsigned int new_sockaddr_len;
    char msg[100];
	char send_msg[]= "hello client";
    //create socket
    mysocket = socket(AF_INET, SOCK_DGRAM,0); //tcp connection
    //bind socket to addr
    my_sockaddr.sin_family = AF_INET;
    my_sockaddr.sin_addr.s_addr = INADDR_ANY;
    my_sockaddr.sin_port = htons(PORT_NUM);
    bind_rtn = bind(mysocket, (struct sockaddr *) &my_sockaddr, sizeof(my_sockaddr));
    if (bind_rtn != 0)
    {
	perror("failed on binding");
	exit(1);
    }
	//run a loop to wait for msg from client,  and send back one msg and then quit
    bzero((char *) &new_sockaddr, sizeof(new_sockaddr));
    new_sockaddr_len = sizeof(new_sockaddr);
    bzero(msg,100);
    while(1){
        if (recvfrom(mysocket, &msg, sizeof(msg),0, (struct sockaddr *)&new_sockaddr, &new_sockaddr_len)>0){
			printf("got msg from client :%s\n",msg);
			sendto(mysocket, &send_msg,sizeof(send_msg),0, (struct sockaddr *)&new_sockaddr, new_sockaddr_len);
			break;
        }
    }

    close(mysocket);
    return 0; 
}

