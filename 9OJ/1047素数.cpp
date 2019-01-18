#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1||n<=0)printf("no\n");
		else{
		int k=sqrt(n);
		int flag=0;
		for(int i=2;i<=k&&flag==0;i++)
		{
			if(n%i==0){
			flag=1;
			break;	
			}
		}
		if(flag==1)printf("no\n");
		else printf("yes\n");
	}
	}
	return 0;
	
 } 

