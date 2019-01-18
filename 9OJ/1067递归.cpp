#include<stdio.h>
double jiecheng(int n)//ÄÜËãµ½170 
{
	if(n==0) return 1;
	else return n*jiecheng(n-1);
}
int main(){
	int n;
	while(scanf("%d",&n))
	{
		printf("%.0lf\n",jiecheng(n)); 
	}
	return 0;
}
