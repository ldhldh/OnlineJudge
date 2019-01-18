#include<stdio.h>
int main(){
	double a[71];
    a[1]=1,a[2]=2;
    for(int i=3;i<=70;i++){
	    a[i]=a[i-1]+a[i-2];
    }//填上所有答案 
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%.0f\n",a[n]);
	}
	return 0;
} 
