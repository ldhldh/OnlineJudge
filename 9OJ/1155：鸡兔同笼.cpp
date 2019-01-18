#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			if(a%2!=0)printf("0 0\n");
			if(a%4==0)printf("%d %d\n",a/4,a/2);
			if(a%4!=0&&a%2==0)printf("%d %d\n",a/4+1,a/2);
		}
	}
	return 0;
} 
