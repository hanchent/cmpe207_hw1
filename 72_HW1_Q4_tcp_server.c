#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NUM 8000  //pick 8000 as the port number

int main()
{
    int mysocket, newsocket;
    int bind_rtn;
    struct sockaddr_in my_sockaddr, new_sockaddr;
    int new_sockaddr_len;
    char msg[] = "got msg from server: hello client";
    //create socket
    mysocket = socket(AF_INET, SOCK_STREAM,0); //tcp connection
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
    // change the socket to listen for connections
    listen(mysocket,5);
    // accept connections
    new_sockaddr_len = sizeof(new_sockaddr);
    newsocket = accept(mysocket, (struct sockaddr *) &new_sockaddr, &new_sockaddr_len);
	
    write(newsocket , &msg, sizeof(msg));
    close(mysocket);
    close(newsocket);
    return 0; 
}

