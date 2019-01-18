#include<stdio.h>
#include<string.h>
    struct E
    {
        char name[101];
        int age;
        int score;
    };
int main()
{
    int N,i,j;
    struct E *a[1000];
    struct E b[1000];
    struct E *z; 
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            a[i]= &b[i];
            scanf("%s%d%d",a[i]->name,&(a[i]->age),&(a[i]->score));
        }//得到序列
        int shouldswap=0;
        for(i=0;i<N-1;i++)
        {
            for(j=0;j<N-1-i;j++)
            {    
                shouldswap=0;
                if(a[j+1]->score<a[j]->score)
                shouldswap=1;
                else if(a[j+1]->score==a[j]->score)
                {
                    if(strcmp(a[j+1]->name,a[j]->name)<0)
                    shouldswap=1;
                    else if(strcmp(a[j+1]->name,a[j]->name)==0)
                    {
                        if(a[j+1]->age<a[j]->age)
                        shouldswap=1;
                    }
                }
                if(shouldswap==1)
                {
                    z=a[j+1];
                    a[j+1]=a[j];
                    a[j]=z; 
                }
            }
        }//冒泡排序
        for(i=0;i<N;i++)
        printf("%s %d %d\n",a[i]->name,a[i]->age,a[i]->score);
        
    }//循环结束
    return 0; 
}
