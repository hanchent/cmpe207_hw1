#include <stdlib.h>
#include <stdio.h>

main(){
    FILE *f;
    f = fopen("72_HW1_Q1_result","w");
    int pid;
    pid = fork();
    if (pid == 0){//the child
	pid = getpid();
        fprintf(f,"printing from 1st child process with pid = %d \n",pid);
    } else {  // the parent
        pid = fork();
	if (pid == 0){ //the second child
	    pid = getpid();
	    fprintf(f,"printg from 2nd child process with pid = %d \n",pid);
	} else { //parent
	    pid = getpid();
	    fprintf(f,"printg from parent process with pid = %d \n", pid);
	}
    }
    exit(0);
}
