#include<stdio.h>
struct E{
	char number[30];
	int eh;
	int em;
	int es;
	int lh;
	int lm;
	int ls;
};
E A[1001];

int eh=24;
int em=60;
int es=60;
int lh=-1;
int lm=0;
int ls=0;
int main()
{
	int N,M,i,j;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
	    {
	    	scanf("%d",&M);
	    	int early,late;
	    	for(j=1;j<=M;j++)
	    	{
	    		scanf("%s %d:%d:%d %d:%d:%d",&A[j].number,&A[j].eh,&A[j].em,&A[j].es,&A[j].lh,&A[j].lm,&A[j].ls);
	    		if(eh>A[j].eh)
	    		{
	    			eh=A[j].eh;
	    			em=A[j].em;
					es=A[j].es;
	    			early=j;
				}
				else if(eh==A[j].eh)
				{
					if(em>A[j].em)
					{
						em=A[j].em;
						es=A[j].es;
						early=j;
					}
					else if(em==A[j].em)
					{
						if(es>A[j].es)
					{
						es=A[j].es;
						early=j;
					}
				}
			}//使A[0]中的时间记录当前数据中，最早签到时间； 
			if(lh<A[j].lh)
	    		{
	    			lh=A[j].lh;
	    			lm=A[j].lm;
					ls=A[j].ls;
	    			late=j;
				}
				else if(lh==A[j].lh)
				{
					if(lm<A[j].lm)
					{
						lm=A[j].lm;
					    ls=A[j].ls;
						late=j;
					}
					else if(lm==A[j].lm)
					{
						if(ls<A[j].ls)
					{
						ls=A[j].ls;
						late=j;
					}
				}
			}//A[0]中的时间记录当前数据中，最晚签到时间； 
			
		}
		printf("%s %s\n",A[early].number,A[late].number);
	} 
	
 } 
 return 0;
}
