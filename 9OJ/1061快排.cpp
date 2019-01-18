#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct E{
	int scort;
	char name[100];
	int age;
}T[1001];

bool cmp(E a,E b)
	{
		if(a.scort!=b.scort)return a.scort<b.scort;
		int tmp= strcmp(a.name,b.name);
		if(tmp!=0)
		return tmp<0;
		else return a.age<b.age;
	}
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		for(int i=0;i<N;i++)
		{
			scanf("%s %d %d",T[i].name,&T[i].age,&T[i].scort);
		}
		sort(T,T+N,cmp);
		for(int i=0;i<N;i++)
		{
			printf("%s %d %d\n",T[i].name,T[i].age,T[i].scort);
		}
	}
	return 0;
}
