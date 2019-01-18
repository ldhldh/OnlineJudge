#include<stdio.h>
int main()
{
	int h;
	while(scanf("%d",&h)!=EOF)
	{
		int k=2*(h-1);
		int m=3*h-2;
		int i,j;
		for(i=0;i<h-1;i++)
		{
			for(j=0;j<m;j++)
			if(j<k)
			printf(" ");
			else if(k<j<m-1)
			{
				printf("*");	
			}
			k-=2;
			printf("\n");
		}
		for(i=0;i<m;i++)
		printf("*");
		printf("\n");
	}
	return 0;
 } 
