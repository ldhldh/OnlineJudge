#include<stdio.h>
 
int main()
{
    int M,N,k=0;
    int x[1000];
    while(scanf("%d",&M))
    {
        ///k++;
        if(M==0)
        break; 
            scanf("%d",&N);
        int i=0,j=0;
        int rows=0,cows=0;
        int A[M][N],B[M][N],R=0,C=0;//C[M][N],D[M][N];
        for(i=0;i<M;i++)
        for(j=0;j<N;j++)
        {
            scanf("%d",&A[i][j]);
            //C[i][j]=0;
        }
        for(i=0;i<M;i++)
        for(j=0;j<N;j++)
        {
            scanf("%d",&B[i][j]);
        }
         
        for( i=0;i<M;i++)
        for( j=0;j<N;j++)
        {
            R+=A[i][j]+B[i][j];
            if(R==0&&j==N-1)
            {
                rows++;//ÐÐ=0 
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
                cows++;//ÁÐ=0 
                C=0;
            }
            else if(C!=0&&i==M-1)
            {
                C=0;
             }  
        } 
        x[k++]=rows+cows;
    }
    int i;
    for(i=0;i<k;i++)
        printf("%d\n",x[i]);
    //printf("%d",cows);
    return 0;
}
