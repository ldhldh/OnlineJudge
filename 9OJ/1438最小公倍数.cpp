#include<stdio.h>
int gyue(int a,int b)
{
	if (b==0)
	return a;
	else 
	return gyue(b,a%b);
 } 
 int main()
 {
 	int a,b,c,d;
 	while(scanf("%d %d",&a,&b)!=EOF)
 	{
 		c=gyue(a,b);
		printf("%d\n",a*b/c);  	
	 }
	 return 0;
 }
