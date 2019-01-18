#include<stdio.h>


int main()
{
	int n,i,j;
	int a[100]; 
	while(scanf("%d",&n)!=EOF)
	{
		if(n>100)break;
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}//µÃµ½ÐòÁÐ
	
	
    for(i=0;i<n-1;i++)
{
	int flag=0;
	for(j=n-1;j>i;j--)
	{
		if(a[j]<a[j-1])
		{
			int tmp=a[j-1];
			a[j-1]=a[j];
			a[j]=tmp;
		    flag=1;
		}
		
	}
	if(flag==0)break;
	}//Ã°ÅÝÅÅÐò 

	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	}
	return 0;
} 
