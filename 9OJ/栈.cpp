#include<stdio.h>
#include<stack>
using namespace std;
stack<int>S;
int main(){
	int a,b,k=0;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if (a==0&&b==0)break;
		int x = a > b ? a : b;
		S.push(x);
		k++;
	}
	for(;k>0;k--)
	{
		printf("%d ",S.top());
	    S.pop();
	}

	return 0;
}
