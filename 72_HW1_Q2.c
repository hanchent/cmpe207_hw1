#include <stdlib.h>
#include <stdio.h>

main(){
    int pid;
    pid = fork();
    if (pid == 0){ //child
	execve("sum.o");
    }else { // parent
	exit(0);
    }
}
