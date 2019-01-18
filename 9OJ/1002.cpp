#include<stdio.h>
#include<math.h>

int P,T,G1,G2,G3,GJ; 

    int max(int a,int b,int c){
    	if(a>b&&a>c)return a;
    	if(b>a&&b>c)return b;
    	if(c>a&&c>b)return c;
    	
	}
int main()
{
	while(scanf("%d %d %d %d %d %d",&P,&T,&G1,&G2,&G3,&GJ)!=EOF)
	{
		if(abs(G1-G2)<=T)
		{
			
			printf("%.1f\n",(double)(G1+G2)/2.0); 
		}
		else {
		if(abs(G3-G1)<=T&&abs(G3-G2)<=T)
		{
		printf("%.1f\n",(double)max(G1,G2,G3));}
		else 
		{ if(abs(G3-G1)>T&&abs(G3-G2)>T)
		 {
		 printf("%.1f\n",(double)GJ);
		 }
		else
		{
		if(abs(G3-G1)<=T&&abs(G3-G2)>T)
		{
			printf("%.1f\n",((double)(G1+G3))/2.0);
		}
		else 
		{
		if(abs(G3-G2)<=T&&abs(G3-G1)>T)
		{
			printf("%.1f\n",((double)(G2+G3))/2.0);
		}
	    }
		}
	    }
	}
}
        return 0;
    }
    
    
 
