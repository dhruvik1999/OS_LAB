#include<stdio.h>

int main(){

	FILE *f1,*f2;

	f1 = fopen("/home/student/Desktop/os/first.java","r");
	f2 = fopen("/home/student/Desktop/third.java","w");

	 char c = fgetc(f1); 
    while (c != EOF) 
    { 
        fputc(c, f2); 
        c = fgetc(f1); 
    }

    fclose(f1);
    fclose(f2);

	return 0;
}