#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
  
int main() 
{
  
    int fd1[2]; 
    int fd2[2]; 
  
    char fixed_str[] = "forgeeks.org"; 
    char input_str[100]; 
    pid_t p; 
  
    if (pipe(fd1)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
    if (pipe(fd2)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
  
    printf("p1  :  enter any message for P2(fork) : ");
    scanf("%s", input_str); 
    p = fork(); 
  
    if (p < 0) 
    { 
        fprintf(stderr, "fork Failed" ); 
        return 1; 
    } 
  
    else if (p > 0) 
    { 
        char concat_str[100]; 
  
        close(fd1[0]); 
 

        write(fd1[1], input_str, strlen(input_str)+1); 
        close(fd1[1]); 
  

        wait(NULL); 
  
        close(fd2[1]); 
  
        read(fd2[0], concat_str, 100); 
        printf("P1  :  message get from p2(fork) ::  %s\n", concat_str); 
        close(fd2[0]); 
    } 
  

    else
    { 
        close(fd1[1]); 

        char concat_str[100]; 
        read(fd1[0], concat_str, 100); 
 
        int k = strlen(concat_str); 
        
        printf("p2  :  Message get from p1(parent) : %s",concat_str);

       printf("\n\np2  enter any message for P2(fork) : " );
       char concat_str2[100]; 
       scanf("%s", concat_str2);
  

        close(fd1[0]); 
        close(fd2[0]); 
  
        write(fd2[1], concat_str2, strlen(concat_str)+1); 
        close(fd2[1]); 
  
        exit(0); 
    } 
} 