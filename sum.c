#include <stdlib.h>
#include <stdio.h>
int sum;
main(){
    FILE *f;
    f = fopen("72_HW1_Q2_result","w");
    int i;
    for(i=0;i<=5;i++){
	sum += i;
     }
     fprintf(f,"the summation is %d \n",sum);
     fclose(f);
     exit(0);
}
