#include<stdio.h>
int gyue(int a,int b)
{
	if(b==0)
	return a;
	else 
	return gyue(b,a%b);
}
int main()
{
	int a,b;
	while (scanf("%d %d",&a,&b)!=EOF)
	{
		printf("%d\n",gyue(a,b));
	}
	return 0;
 } 
