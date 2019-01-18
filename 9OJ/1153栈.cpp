#include<stdio.h>
#include<string.h>
int a[100]; 
char s[101];
int main()
{
	int i,j;
	while(scanf("%s",s)!=EOF)
{
	int count=0;
    for(i=0;i<100;i++)
	a[i]=0;	
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==')')
		{
			count--;
			if(count<0)
			{
				a[i]-=1;
				count=0;
			}
			else if(count>=0)
			{
				for(j=0;j<i;j++)
				{
					if(a[j]>0)
					{
						a[j]-=1;
					}
				} 
			}
		}
		if(s[i]=='(')
		{
			count++;
			
				a[i]+=1;
				for(j=0;j<i;j++)
				{
					if(a[j]>0)
					a[j]+=1;
				} 
				
		}
	}
	
	printf("%s\n",s);
	for(i=0;s[i]!='\0';i++)
	{
		if(a[i]<0)
		printf("?");
		else if(a[i]==0)
		printf(" ");
		else if(a[i]>0)
		printf("$");
	}
	printf("\n");
}
	return 0;
}
