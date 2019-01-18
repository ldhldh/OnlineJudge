#include<stdio.h>
#include<string.h>
     struct student
{
	char name[101];
	int age;
	int score;
};
    int i,j,N,shouldswap;
	struct student a[1000];
	struct student z;
int main()
{
	
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
		scanf("%s%d%d",a[i].name,&a[i].age,&a[i].score);
		//µ√µΩ–Ú¡–
		for(i=0;i<N-1;i++)
		{
			for(j=0;j<N-1-i;j++)
			shouldswap=0;
			if(a[j].score>a[j+1].score)
			shouldswap=1;
			else if(a[j].score==a[j+1].score)
			{
				if(strcmp(a[j].name,a[j+1].name)>0)
				shouldswap=1;
				else if(strcmp(a[j].name,a[j+1].name)==0)
				{
				    if(a[j].age>a[j+1].age)
					shouldswap=1;	
				}
			}
			if(shouldswap==1)
			{
				z=a[j+1];
				a[j+1]=a[j];
				a[j]=z;
			}
		 } //√∞≈›≈≈–Ú 
		 for(i=0;i<N;i++)
		 printf("%s %d %d\n",a[i].name,a[i].age,a[i].score);
		 printf("%s",z.name);
	}
	return 0;
	
}
