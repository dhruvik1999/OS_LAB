#include<bits/stdc++.h>
using namespace std;

int main(){

	int n = 5;
	int av[n][3] = {{2,1,0},{5,1,2},{4,5,0},{0,5,8},{7,5,0}};
	int ma[n][3] = {{6,4,3},{7,8,9},{5,6,2},{4,6,9},{8,9,1}};
	int ch[n][3];
	int x=5,y=1,z=6;

	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			ch[i][j] = ma[i][j]-av[i][j];
		}
	}

	int i = 0,ai=0;

	while(ai!=5){
		i=i%n;
		if(ch[i][0] <= x && ch[i][1] <= y && ch[i][2] <= z){
			x+=av[i][0];
			y+=av[i][1];
			z+=av[i][2];

			ch[i][0]=1000;
			ch[i][1]=1000;
			ch[i][2]=1000;

			cout << i << "\n";
			ai++;
		}
		i++;
	}

	return 0;
}