#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
typedef struct
{
    char no[100];
    char name[100];
    char sex[5];
    int age;
}stu;
stu s[1000];
char no[10000][100];
int cmp(const void*a,const void*b)
{
    return strcmp((*(stu *)a).no,(*(stu *)b).no)>0;
}
int main()
{
    int n,m,i,low,high,mid,f,t;
    while(scanf("%d",&n) != EOF)
    {
        for(i=0;i<n;i++)
            scanf("%s%s%s%d",s[i].no,s[i].name,s[i].sex,&s[i].age);
        qsort(s,n,sizeof(s[0]),cmp);
        f=0;
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%s",no[i]);
        for(i=0;i<m;i++)
        {
            low=0,high=n-1;
            f=-1;
            while(low<=high)
            {
                mid=(low+high)/2;
                t=strcmp(no[i],s[mid].no);
                if(t==0)
                {
                    f=mid;
                    break;
                }
                else if(t>0)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            if(f==-1)
                printf("No Answer!\n");
            else
                printf("%s %s %s %d\n", s[f].no,s[f].name,s[f].sex,s[f].age);
        }
    }   
    return 0;
}
