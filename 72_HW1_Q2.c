#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int pid;
    pid = fork();
    if (pid == 0){ //child
		execve("sum.o",NULL,NULL);
    }else { // parent
	//exit(0);
		return 0;
    }
}
