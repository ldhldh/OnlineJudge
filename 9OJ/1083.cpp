#include<stdio.h>
int main()
{
	int m,n;
	int a[9],b[9]; 
	while(scanf("%d %d",&m,&n)!=EOF){
		int sum=0;
		for(int i=0;i<9;i++)
		{
			a[i]=m%10;
			b[i]=n%10;
			m=m/10;
			n=n/10;
		}
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			sum+=a[i]*b[j];
		}
		printf("%d\n",sum);
	}
	return 0;
}
