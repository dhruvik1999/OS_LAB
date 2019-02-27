#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <string.h> 
#include <stdlib.h>

int main(){


	pid_t pid;
	int n;

	printf("Enter the number : ");
	scanf("%d",&n);

	pid=fork();

	if(pid<0){
		printf("Child proces not created\n");
	}else if(pid == 0){
		int fact = 1,i;
		for(i=1;i<=n;i++){
			fact=fact*i;
		}
		printf("factorial of %d is %d",n,fact);
	}
}