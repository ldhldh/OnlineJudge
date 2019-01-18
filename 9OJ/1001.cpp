#include<stdio.h>
int main()
{
	int M,N,x[1000],k=0;
	while(scanf("%d",&M)!=EOF)
	{
		if(M==0)break;
		scanf("%d",&N);
		int A[M][N],B[M][N],i,j;
		int R=0,C=0,rows=0,cows=0;
		for(i=0;i<M;i++)
		for(j=0;j<N;j++)scanf("%d",&A[i][j]);
		for(i=0;i<M;i++)
		for(j=0;j<N;j++)scanf("%d",&B[i][j]);
		
		
		//上边已验证正确 
		
		for( i=0;i<M;i++)
		for( j=0;j<N;j++)
		{
			R+=A[i][j]+B[i][j];
			if(R==0&&j==N-1)
			{
				rows++;
				R=0;
			}
			else if(R!=0&&j==N-1)
			{
			    R=0;
			}
	 }
	 
	    for( j=0;j<N;j++)
	    for( i=0;i<M;i++)
		{
			C+=A[i][j]+B[i][j];
			if(C==0&&i==M-1)
			{
				cows++;
				C=0;
			}
			else if(C!=0&&i==M-1)
			{
			C=0;
			}
	 }
	 
	 //下边已验证正确 
	 
		x[k++]=rows+cows;
	}
	int i;
	for(i=0;i<k;i++)
	printf("%d\n",x[i]);
	return 0;
} 
