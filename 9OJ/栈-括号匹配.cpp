#include<stdio.h>
#include<stack>
using namespace std;
char a[101];
char ans[101];
stack<char>S;
int main()
{
	while(scanf("%s",a)!=EOF)
	{
		int i;
		for(i=0;a[i]!=0;i++)
		{
			if (a[i]=='(')
			{
				S.push(i);
				ans[i]=' ';
			}
			if (a[i]==')')
			{
				if(S.empty()==false)
				{
					S.pop();
					ans[i]=' ';
				}
				else ans[i]='?';
			}
			else ans[i]=' ';
		}
		while(!S.empty())
		{
			ans[S.top()]='$';
			S.pop();
		}
		ans[i]=0;
		printf("%s\n",a);
		printf("%s\n",ans);
	}
	return 0;
}
