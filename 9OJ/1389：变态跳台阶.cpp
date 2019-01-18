#include<stdio.h>
int main(){
	double a[51];
	a[1]=1;
	for(int i=2;i<=50;i++){
		a[i]=a[i-1]*2;
	}
	int n;
	while(scanf("%d",&n)!=EOF&&n<51&&n>0){
		printf("%.0f\n",a[n]);
	}
	return 0;
} 
