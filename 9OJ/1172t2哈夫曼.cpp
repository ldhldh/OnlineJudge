#include <stdio.h>
#include <stdlib.h>
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main()
{
    int buf[1000];
    int i,j;
    int n;
    int tmp;
    int sum=0;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&buf[i]);
        }
         
        for(i=1;i<n;i++)//排序，权值最大在前 
        {
            for(j=0;j<n-i;j++)
            {
                if(buf[j]<buf[j+1])
                {
                    tmp=buf[j];
                    buf[j]=buf[j+1];
                    buf[j+1]=tmp;
                }
            }
        }
         
        sum=0;
        for(i=n-1;i>0;i--)
        {
            sum+=buf[i]+buf[i-1];
            buf[i-1]=buf[i]+buf[i-1];
            n--;
             
            //for(i=1;i<n;i++)//排序，权值最大在前 
            //{
            //for(j=0;j<n-i;j++)
            //{
            //  if(buf[j]<buf[j+1])
            //  {
            //      tmp=buf[j];
            //      buf[j]=buf[j+1];
            //      buf[j+1]=tmp;
            //  }
            //}
            //}
            for(j=n;j>0;j--)
            {
                if(buf[j]>buf[j-1])
                {
                    tmp=buf[j];
                    buf[j]=buf[j-1];
                    buf[j-1]=tmp;
                }
            }
        }
         
        printf("%d\n",sum);
     
    }
    return 0;
}
/**************************************************************
    Problem: 1172
    User: 18215598719
    Language: C
    Result: Accepted
    Time:10 ms
    Memory:912 kb
****************************************************************/
