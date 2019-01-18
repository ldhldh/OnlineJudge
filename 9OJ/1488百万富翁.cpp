#include<stdio.h>
int main(){
	int M=300;
	double Y=1;
	for(int i=30;i>0;i--){
		Y*=2;
	}
	Y-=1;
	printf("%d %.0f\n",M,Y);
	return 0;
}
