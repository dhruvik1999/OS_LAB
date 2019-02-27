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
		char* A_list[]={"ls","/home"};
		execvp("ls",A_list);
		exit(0);
	}else{
		printf("parent process pid = %u \n",getpid());
	}
	return 0;
}