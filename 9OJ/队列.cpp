#include<stdio.h>
#include<queue>
using namespace std;
queue<int>Q;
int main(){
	int a,b,k=0;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if (a==0&&b==0)break;
		int x = a > b ? a : b;
		Q.push(x);
		k++;
	}
	for(;k>0;k--)
	{
		printf("%d ",Q.front());
	    Q.pop();
	}
	return 0;
}
