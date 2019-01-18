#include<stdio.h>
#include<queue>
using namespace std;
queue<int>Q;

int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		if(m==0&&n==0)break;
		int count=1;
		int j=0;
		Q.push(m);
		for(;Q.front()<=n;j++)
		{
			int x=Q.front(); 
			if(2*x<=n)
			{
				Q.push(2*x);
				count++;
			}
			
			if(2*x+1<=n)
			{
				Q.push(2*x+1);
				count++;
			}
			else break;
			Q.pop();
			
		}
		printf("%d\n",count);
	}
	return 0;
}
