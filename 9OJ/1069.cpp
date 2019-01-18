#include<stdio.h>
#include<string.h>
struct student {
	int number;
	char name[100];
	char sex[50];
    int age;
};
int buf[10000];
struct student a[1000];
struct student *b[1000];
struct student *z;
int main()
{
	int i,j,N,M,x;
	int high,low,mid;
	while (scanf("%d",&N)!=0)
	{
		for(i=0;i<N;i++)
		{
			b[i]=&a[i];
			scanf ("%d%s%s%d",&(b[i]->number),b[i]->name,b[i]->sex,&(b[i]->age));
		}//得到序列
		for(i=0;i<N-1;i++)
		{
			for(j=0;j<N-i-1;j++)
			{
				if(b[j]->number>b[j+1]->number)
				{
				z=b[j];
				b[j]=b[j+1];
				b[j+1]=z;
				}
			}
		 } //冒泡排序
		//for(i=0;i<N;i++)
	//printf("%d %s %s %d",b[i]->number,b[i]->name,b[i]->sex,b[i]->age);
		 
		 if(scanf("%d",&M)!=EOF)
	{
		 for(i=0;i<M;i++)
		 {
		 	scanf("%d",&buf[i]);
		 }
		 for(i=0;i<M;i++)
		 {
		 	low=1,high=N;
		    
		 	x=buf[i];
		 	while(low<=high)
		 	{   
		 	    mid=(low+high)/2;
		 	    if(b[mid-1]->number==x)break;
		 		else if(b[mid-1]->number>x)
		 		{
		 			high=mid-1;
		 			
				 }
				else if(b[mid-1]->number<x)
		 		{
		 			low=mid+1;
		 			
				}	
			 
		    }
		    if(low>high)
		 	printf("No Answer!\n");
			else if(b[mid-1]->number==x)
	printf("%d %s %s %d\n",b[mid-1]->number,b[mid-1]->name,b[i]->sex,b[mid-1]->age);
		 	 
		  }//二分法查找 
		  
	}//输入M，及M个序号，并输出 
	
	}
	return 0;
}//九度runtime error 
