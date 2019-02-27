#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <string.h> 
#include <stdlib.h>

int main(){
	pid_t pid;
	int set = 1;
	pid = fork();

	if(pid==1){
		printf("Can't fork,error");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		printf("Child process pid = %u \n",getpid());
		execvp("./sample",NULL);
		exit(0);
	}else{
		printf("parent process pid = %u \n",getpid());

		if(waitpid(pid,&set,0)==pid){
			printf("\n\nwaitting done\n");
		}
	}
	return 0;
}