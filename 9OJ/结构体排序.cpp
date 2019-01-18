#include<stdio.h>
#include<string.h>
struct student {
	int number;
	char name[100];
	char sex[50];
    int age;
};
struct student a[1000];
struct student *b[1000];
struct student *z;
int main()
{
	int i,j,N;
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
				{               //这一对括号必须加！！！！！！！！！！！！ 
				z=b[j];
				b[j]=b[j+1];
				b[j+1]=z;
				}
			}
		 } //冒泡排序
		 for(i=0;i<N;i++)
	printf("%d %s %s %d\n",b[i]->number,b[i]->name,b[i]->sex,b[i]->age);
}
return 0;
}

