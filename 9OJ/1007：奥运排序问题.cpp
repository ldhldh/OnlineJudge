#include<stdio.h>
int main(){
	int N,M;
	while(scanf("%d%d",&N,&M)!=EOF){
		double a[N][3];
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf("%lf",&a[i][j]);	
			}
		}
		int m[M];
		for(int i=0;i<M;i++)
		{
		scanf("%d",&m[i]);
		}//get所有输入 
		for(int i=0;i<M;i++)
		{
			int R=m[i];
			int k1=1,k2=1,k3=1,k4=1;
			for(int j=0;j<M;j++)
			{
				if(a[m[j]][0]>a[R][0])k1++;
				if(a[m[j]][1]>a[R][1])k2++;
				if(a[m[j]][0]/a[m[j]][2]>a[R][0]/a[R][2])k3++;
				if(a[m[j]][1]/a[m[j]][2]>a[R][1]/a[R][2])k4++;
			}
			if(k1<=k2&&k1<=k3&&k1<=k4)
			{
				printf("%d:%d\n",k1,1);continue;
			}
			if(k2<k1&&k2<=k3&&k2<=k4)
			{
				printf("%d:%d\n",k2,2);continue;
			}
			if(k3<k1&&k3<k2&&k3<=k4)
			{
				printf("%d:%d\n",k3,3);continue;
			}
			if(k4<k1&&k4<k2&&k4<k3)
			{
				printf("%d:%d\n",k4,4);continue;
			}
		 }
		 printf("\n");//输出 
	}
	return 0;
} 
